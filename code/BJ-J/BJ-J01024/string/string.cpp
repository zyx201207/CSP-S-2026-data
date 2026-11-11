#include<bits/stdc++.h>
using namespace std;
long long n,ans,sum=0;
string s;
struct t{
    long long num;
    char ch;
} T[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>T[i].num>>T[i].ch;
        sum+=T[i].num;
    }
    //cout<<s<<endl;
    long long now=1;
    while(now<n){
        for(long long j=0;j<T[now].num;T[now].num--){
            if(T[n].num==0){
                n--;
            }
            ans+=(T[now].ch!=T[n].ch);
            T[n].num--;
        }
        now++;
    }
    cout<<ans;
    return 0;
}
