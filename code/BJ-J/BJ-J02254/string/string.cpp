#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
char c[N];
int main(){
    int n,a,p=0,l;
    char x;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    bool b=n&1;
    long long ans=0;
    vector<int>v(n);
    for(int i=0;i<n;++i){
        cin>>a>>x;
        if((long long)n*a>N)return 0;
        l=p;
        while(++p){
            if(l+a==p)break;
            c[p]=x;
        }
        p=l+a;
    }
    for(int i=0,j=n-1;j-i||(b&&i!=j);++i,--j){
        if(c[i]!=c[j])++ans;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
