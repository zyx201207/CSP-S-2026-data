#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define pll pair<int,int>
const int N=2e5+5;
int n;
int a[N],sheng[N];
char c[N];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++)sheng[i]=a[i];
	int l=1,r=n;
	while(l<r){
		int mi=min(sheng[l],sheng[r]);
		ans+=mi*(c[l]!=c[r]);
		sheng[l]-=mi,sheng[r]-=mi;
		if(sheng[l]==0)l++;
		if(sheng[r]==0)r--;
	}
	cout<<ans;
	return 0;
}
