
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i,j,k) for(register int i=j;i<=k;i++)
const int N=5e5+5;
int n,m,x,y,k,cnt,a[N],ans[N],card[N],top,frt=1;
void chk(int top){
    int flag=0;
    fo(i,1,top-1)if(card[i]==card[top]) flag=i;
    if(flag)
        fo(i,flag,top-1) card[i]=0;
    return;
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    fo(i,1,n) cin>>a[i];
    fo(game,1,n){
        top=1;
        fo(i,game,n){
            card[++top]=a[i];
            chk(top);//1 dao top fei 0 de shi youxiao card shuzu
            //fo(i,1,top) cout<<card[i];
            //cout<<endl;
        }
        //cout<<top;
        fo(i,1,top){
            //if(card[i])cout<<card[i];
            if(card[i]&&card[i]<=m) ans[card[i]]++;}
        //cout<<endl;
    }
    fo(i,1,m) cout<<ans[i]<<" ";
    return 0;
}
