#include<bits/stdc++.h>
#define N 200010
#define int long long
using namespace std;

int n;
int l1[N],r1[N],l2[N],r2[N];
string s1,s2;

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x; char ch;
        cin>>x>>ch;
        l1[i]=r1[i-1]+1;
        r1[i]=r1[i-1]+x;
        s1=s1+ch;
        s2=ch+s2;
    }
    for(int i=1;i<=n;i++){
        l2[i]=r1[n]-r1[n-i+1]+1;
        r2[i]=r1[n]-l1[n-i+1]+1;
    }
    int p1=1,p2=1,ans=0;
    int sy1=r1[1]-l1[1]+1;
    int sy2=r2[1]-l2[1]+1;
    while(p1!=n+1&&p2!=n+1){
        if(r1[p1]>r2[p2]){
            sy1-=sy2;
            if(s1[p1-1]!=s2[p2-1]) ans+=sy2;
            sy2=r2[p2+1]-l2[p2+1]+1;
            p2++;
        }
        else if(r1[p1]<r2[p2]){
            sy2-=sy1;
            if(s1[p1-1]!=s2[p2-1]) ans+=sy1;
            sy1=r1[p1+1]-l1[p1+1]+1;
            p1++;
        }
        else{
            if(s1[p1-1]==s2[p2-1]){
                p1++;
                p2++;
                sy1=r1[p1]-l1[p1]+1;
                sy2=r2[p2]-l2[p2]+1;
            }
            else{
                ans+=(sy1>sy2 ? sy1 : sy2);
                p1++;
                p2++;
                sy1=r1[p1]-l1[p1]+1;
                sy2=r2[p2]-l2[p2]+1;
            }
        }
    }
    cout<<ans/2;
    return 0;
}