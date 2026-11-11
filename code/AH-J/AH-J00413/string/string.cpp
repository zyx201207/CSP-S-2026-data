#include<bits/stdc++.h>
using namespace std;
long long n,cnt,il,x,ans;
string ds,x1;
struct str{
    int g,q;
    char s;
}b[200005];
struct stu{
    int dd;
    char z;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].g;
        cin>>b[i].s;
        b[i].q+=b[i].g+b[i-1].q;
    }
    cnt=b[n].q/2;
    for(int i=n;i>=1;i--){
        if(cnt>=b[i].q){
            il=i;
            break;
        }
    }
    x=b[il+1].q-cnt;
    x1=b[il+1].s;
    for(int i=1;i<=il;i++){
        if(i==il){
            if(x1[i]==b[i].s){
                b[i].g+=x;
            }else if(x1[n-i+1]==b[n-i+1].s){
                b[n-i+1].g+=x;
            }
        }
        if(b[i].s==b[n-i+1].s&&a[i].z==b[i].s){
            a[i].dd=max(b[i].g,b[n-i+1].g)-min(b[n-i+1].g,b[i].g);
            a[i].z=b[i].s;
        }else if(b[i].s!=b[n-i+1].s){
            a[i].dd=max(b[i].g,b[n-i+1].g)-min(b[n-i+1].g,b[i].g);
            ans+=min(b[n-i+1].g,b[i].g);
            if(b[i].g>b[n-i+1].g){
                a[i].z=b[i].s;
            }else if(b[i].g<b[n-i+1].g){
                a[i].z=b[n-i+1].s;
            }
        }
    }
    cout<<ans;
    return 0;
}

