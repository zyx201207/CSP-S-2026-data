#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
string s,b,a,c,z;
long long n,m;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>s;
    n=(a[0]-'0')*10+a[1]-'0';
    m=(c[0]-'0')*10+c[1]-'0';
    if(m==n){
            cout<<1;
            int q=(b[0]-'0')*10+b[1]-'0';
            int w=(s[0]-'0')*10+s[1]-'0';
            if(q==w){
                cout<<1;
                if(b[2]>='A'&&b[2]<='C'&&s[2]>='A'&&s[2]<='C'){
                    cout<<1;
                    n=b[2]-'0';
                    m=s[2]-'0';
                    if(n+1==m||n-1==m) cout<<1;
                    else cout<<0;
                }else if(b[2]=='D'||b[2]=='F'&&s[2]=='D'||s[2]=='F'){
                    cout<<1<<1;
                }else{
                    cout<<0<<0;
                }
            }else{
                cout<<'0'<<'0'<<'0';
            }
    }
    else cout<<'0'<<'0'<<'0'<<'0';
    return 0;
}
