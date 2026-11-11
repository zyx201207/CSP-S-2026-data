#include<bits/stdc++.h>
using namespace std;
long long n,ans=0;
struct node{
    int a;
    char c;
}s[200005];
int solve(int x,int y){
    if(x==y) return 4;
    int op=min(s[x].a,s[y].a);
    if(s[x].c==s[y].c){
        s[x].a-=op;
        s[y].a-=op;
    }
    else{
        ans+=op;
        s[x].a-=op;
        s[y].a-=op;
    }
    if(s[x].a==0&&s[y].a==0) return 3;
    else if(s[x].a==0) return 1;
    else if(s[y].a==0) return 2;
    else return 0;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].a>>s[i].c;
    }
    int l=1,r=n;
    while(l<=r){
        switch(solve(l,r)){
            case 1:
            l++;
            break;
            case 2:
            r--;
            break;
            case 3:
            case 4:
            l++,r--;
            break;
            case 0:
            break;
        }
    }
    cout<<ans<<'\n';
    return 0;
}