#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const int maxn=5e5+10;
const int maxnn=3e5+10;
ll n,m;
ll a[maxn],last[maxn],ans[maxnn],llast[maxnn];
bool b[maxn];
void yes(int x){
	for(int i=x;i<=n;i++){
		if(last[i]!=i&&b[last[i]]==0&&last[i]>=x){
			for(int j=last[i];j<i;j++){
				b[j]=1;
			}
		}
	}
	for(int i=x;i<=n;i++){
		if(b[i]==0){
			++ans[a[i]];
		}
		else b[i]=0;
	}
	return;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		last[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(llast[a[i]]==0){
			llast[a[i]]=i;
		}
		else {
			last[i]=llast[a[i]];
			llast[a[i]]=i;
		}
	}
	for(int x=1;x<=n;x++){
		yes(x);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

