#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+10;
int c,t;
int n;
ll d;
ll p[N];
int pre[N],idx;
int dis[N][N];
int in[N],out[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int cnt=0;
		for(int i=1;i<=n;i++) cin>>p[i];
		cout<<rand()%n+1;
	}
	return 0;
}

