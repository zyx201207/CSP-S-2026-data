#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,M=31;
int n,m,a[N],po2[M],ans;
bool v[N],x[N][31];
signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	po2[0]=1;
	for(int i=1;i<=30;i++)
		po2[i]=po2[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[i]=1;
	}
	for(int i=1;i<=n;i++){
		int c=a[i];
		for(int j=30;j>=0;j--)
			if(c>=po2[j])
				x[i][j]=1,c-=po2[j];
	}
	for(int j=30;j>=0;j--){
		int s=0;
		for(int i=1;i<=n;i++)
			if(v[i]&&x[i][j])
				s++;
		if(s<m)
			continue;
		ans+=po2[j];
		for(int i=1;i<=n;i++)
			if(!x[i][j])
				v[i]=0;
	}
	cout<<ans<<"\n";
	
	return 0;
} 
// 9:19 ：T1 T3 并通过大样例 
