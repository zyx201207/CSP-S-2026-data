#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int n,cnt[N];
ll d,x[N];
int f[5010];
inline void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    ll op=x[2]-x[1];
    bool fl=0;
    for(int i=2;i<n;i++)fl|=(op!=x[i+1]-x[i]);
    if(!fl){
        int p=d/op;
        if(!p||p==1){
            cout<<"0\n";
            return;
        }
        int ans=0;
        ans=max(0,n-(p+p)+1);
		cout<<ans<<"\n";
		return;
    }
    if(x[n]-x[1]<=d){
    	cout<<"0\n";
		return;
	}
    int ans=0;
	for(int i=1;i<n;i++){
		for(int j=0;j<=n+5;j++)cnt[j]=0,f[j]=0;
		f[i]=1;cnt[0]=1;
		int l=i;
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[j-1]>d)break;
			while(x[j]-x[l]>d){
                int p=(x[l]-x[i]+d-1)/d;
                cnt[p]-=f[l];
                l++;
            }
            int p=(x[j]-x[i]+d-1)/d;
            for(int k=p;k<=p+5;k++){
            	if(cnt[k-1]>0){p=k;break;}
			}
			f[j]=cnt[p-1];
            cnt[p]+=f[j];
            ans+=(f[j]==2);
		}
	}
    cout<<ans<<"\n";
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)solve();
    return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/



























/*
人因什么而坚持？在场众仙都能回答这个问题。
有人因信仰而坚持，有人因责任而坚持，有人因爱情而坚持。
而方源呢。
我曾经呐喊过，但渐渐地，我发不出声来；
我曾经哭泣过，但渐渐地，我流不出泪来；
我曾经喜悦过，但渐渐地，我看破了世态；
如今，我只剩下面无表情。
这就是我，方源，一个小人物的坚持。
这一刻，光芒四射，坚持仙蛊在此刻炼成了。
*/
