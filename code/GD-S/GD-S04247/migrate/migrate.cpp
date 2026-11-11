#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+15;
ll n,d,x[N],c[N],tl[N],tg[N],ans;
void solve(){
	ans=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++)cin>>x[i];
	for(ll i=1,j=1;j<=n;j++){
		while(x[j]-x[i]>d)i++;
		tl[j]=i;
	}
	for(ll i=1;i<=n;i++){
		tg[i]=0,c[i]=0;
		for(ll j=i+1;j<=n;j++){
			int jp=max(tl[j],i);
			if(jp==j)break;
			if(jp+2<j&&c[jp+2]==c[jp])tg[j]=2;
			else if(jp+1<j&&c[jp]==c[jp+1]){
				if(!tg[jp]&&!tg[jp+1])tg[j]=1,ans++;
				else tg[j]=2;
			}
			else{
				tg[j]=tg[jp];
				if(tg[j]==1)ans++;
			}
			c[j]=c[jp]+1;
		}
	}
	cout<<ans<<"\n";
}
void solveA(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	ll cj=d/(x[2]-x[1]);
	if(cj<2)cout<<"0\n";
	else cout<<max(n-(cj<<1)+1,(ll)0)<<"\n";
}
void solveB(){
	ll f;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	if(n==3){
		cout<<"0\n";
		return;
	}
	if(n==4){
		if(x[4]-x[1]<=d)cout<<"0\n";
		else if(x[2]-x[1]<=d&&x[4]-x[2]<=d&&x[3]-x[1]<=d&&x[4]-x[3]<=d)cout<<"1\n";
		else cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++){
		if(x[i]-x[1]<=d&&x[n]-x[i]<=d){
			f=i;
			break;
		}
	}
	for(int i=1,j=1;i<=n;i++){
		while(j<=n&&x[j]-x[i]<=d)j++;
		tl[i]=j-1;
	}
	for(int i=1;i<f;i++)ans+=tl[tl[i]-1]-tl[tl[i]-2];
	cout<<ans<<"\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T,cc;
	cin>>cc>>T;
	if(cc<=10)while(T--)solve();
	if(cc==11||cc==12)while(T--)solveA();
	if(cc==13||cc==14)while(T--)solveB();
	return 0;
}
