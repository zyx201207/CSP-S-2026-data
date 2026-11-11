#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define ull unsigned long long
#define endl '\n'
#define INF 0x3f3f3f3f
#define lowbit(x) (x&(-x))
#define pll pair<int,int>
const int N=2e5+5,M=31;
int n,m,a[N];
int p[N][M];
int have[N];
int now[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=29;j++){
			if(a[i]&(1<<j)){
				p[i][j]=1;
				have[j]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=29;j++){
			if(have[j]>=m&&p[i][j])now[i]+=(1<<j);
		}
	}
	sort(1+now,1+now+n,cmp);
	int ans=now[1];
	for(int i=2;i<=m;i++)ans=(ans&now[i]);
	cout<<ans;
	return 0;
}

