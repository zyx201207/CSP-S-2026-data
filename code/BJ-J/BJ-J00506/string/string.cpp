#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
struct o{
    int x;
    string y;
}s[N];
long long n,a[N],cnt,l,r,sum,res;
char c;
string k;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        cnt+=a[i];
        s[c-'0'].x+=a[i];
        s[c-'0'].y=c;
        for(int j=1;j<=a[i];j++){
            k+=c;
        }
    }
    if(cnt%2==0){
        l=cnt/2-1;
        r=cnt/2;
        res=cnt-r-1;
    }else{
        l=cnt/2;
        r=l;
        res=cnt-r-1;
    }
        int j=cnt;
        for(int i=1;i<=cnt;i++){
            if(i==j){
                break;
            }
            if(k[i]!=k[j]){
                if(s[k[i]-'0'].x>s[k[j]-'0'].x){
                    k[j]=k[i];
                }else{
                    k[i]=k[j];
                }
                sum++;
            }
            j--;
        }
    cout<<sum;
    return 0;
}

