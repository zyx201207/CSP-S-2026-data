#include<bits/stdc++.h>
using namespace std;
long long n,m,l,cnt,k,r;
long long a[20005];
struct hwc{
    long long sm;
    char zf;
}b[20005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].sm>>b[i].zf;
        l+=b[i].sm;
    }if(n==1){
        cout<<0;
        return 0;
    }k=0;
    r=l;
    long long i=1,j=n;
    while(k<r&&i<j){
        long long q=min(b[i].sm,b[j].sm);
        if(b[i].zf==b[j].zf){
            if(b[i].sm>b[j].sm){
                b[j].sm=0;
                b[i].sm-=q;
                j--;
                r-=q;
                k+=q;
            }else if(b[i].sm<b[j].sm){
                b[i].sm=0;
                b[j].sm-=q;
                i++;
                k+=q;
                r-=q;
            }else if(b[i].sm==b[j].sm){
                b[i].sm=0;
                b[j].sm=0;
                i++;
                j--;
                k+=q;
                r-=q;
            }
        }
        else{
            if(b[i].sm>b[j].sm&&b[i].zf!=b[j].zf){
                cnt+=b[j].sm;
                b[j].sm=0;
                b[i].sm-=q;
                j--;
                r-=q;
                k+=q;
            }else if(b[i].sm<b[j].sm&&b[i].zf!=b[j].zf){
                cnt+=b[i].sm;
                b[i].sm=0;
                b[j].sm-=q;
                i++;
                k+=q;
                r-=q;
            }else if(b[i].sm==b[j].sm&&b[i].zf!=b[j].zf){
				cnt+=q;
                b[i].sm=0;
                b[j].sm=0;
                i++;
                j--;
                k+=q;
                r-=q;
            }
        }
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
}
