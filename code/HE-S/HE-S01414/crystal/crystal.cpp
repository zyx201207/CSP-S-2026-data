#include<bits/stdc++.h>
#define ll long long
#define IOS cin.tie(0)->sync_with_stdio(0);
using namespace std;
const int N=1e6;
ll n,m;
ll a[N+10];
ll dbc[N+10];
ll cha[N+10];
ll q[N+10];
void solve(){
	ll ans;
	ans=1;
	ll cnt=1;
	cin>>n>>m;
	ll op=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) dbc[i]=a[i+1]-a[i];
	for(int i=1;i<n;i++){
		for(int j=i;j<n;j++){
			if(op-dbc[j]>=0){
				op-=dbc[j];
				dbc[j+1]*=(j+2-i); 
				cnt++;
			}
			else if(op-dbc[j]<0){
				dbc[j]/=(j-i+1);
				break;
			}
		}
		ans=max(cnt,ans);
		cnt=1;
		op=m;
	}
	cout<<ans;
}
int main(){
	IOS;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	solve();
	/*
	14 7
	-10 -1 1 1 1 3 4 5 7 8 8 8 9 10
	
	12 3
	-3 -1 1 1 1 1 7 7 7 8 8 8
	*/
	return 0;
}
//余烬还是没能重燃，我还是好好学whk吧
//看到此条送我上迷惑代码大赏
/*
球球了这道题能不能给我40+，我真的想了三个小时 只能想出来一个O(n2)的做法但是样例4假了。
希望我27高考能冲进华中科大，到那时我们再会，OI。
Through those rainbows,shadows,stuggles ans muddles
clearly I saw my way to the destiny
There's something no one can take from me.
*/ 
