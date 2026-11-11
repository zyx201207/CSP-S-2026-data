#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n;
long long ans;
pair<int,char> s1[N],s2[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("strint.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        s1[i]={a,c};
        s2[n-i+1]={a,c};
    }
    int h1=1,h2=1;
    while(h1<=n&&h2<=n){
        int a1=s1[h1].first,a2=s2[h2].first;
        char c1=s1[h1].second,c2=s2[h2].second;
        int t=min(a1,a2);
        ans+=t*int(c1!=c2);
        s1[h1].first-=t;
        s2[h2].first-=t;
        if(s1[h1].first==0)h1++;
        if(s2[h2].first==0)h2++;
    }
    cout<<ans/2;
    return 0;
}
