#include<iostream>
#define int long long
using namespace std;

const int MAXN=2e5+5;
int n,len,a[MAXN];
char c[MAXN];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i],len+=a[i];
    int s1=1,p1=1,s2=n,p2=a[n],l=1,r=len,ans=0;
    while(true){
        int dl=a[s1]-p1+1;
        int dr=p2;
        int ns1=s1,np1=p1;
        int ns2=s2,np2=p2;
        int mv;
        if(l+dl-1>=r-dr+1)break;
        if(dl<dr)mv=dl,ns1++,np1=1,np2-=dl;
        else if(dl>dr)mv=dr,ns2--,np2=a[ns2],np1+=dr;
        else mv=dl,ns1++,np1=1,ns2--,np2=a[ns2];
        if(c[s1]!=c[s2])ans+=mv;
        s1=ns1,p1=np1;
        s2=ns2,p2=np2;
        l+=mv,r-=mv;
    }
    cout<<ans<<endl;
    return 0;
}