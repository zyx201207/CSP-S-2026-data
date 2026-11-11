#include<bits/stdc++.h>
using namespace std;
const int MAX_N=2E5+78;
long long n,m,gw,N[MAX_N],ans=-1;
//bool bj[MAX_N][65];
vector<long long>a;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
//	cout<<n<<' '<<m<<'\n';
	for(int i=1;i<=n;i++){
		int ld=0,x;
		cin>>x;
		N[i]=x;
//		while(x){
//			bj[i][ld]=x%2;
//			if(x%2==1){
//				gw=max(gw,ld);
//			}
//			ld++;
//			x/=2;
//		}
	}
	sort(N+1,N+n+1);
	for(int i=n;i>=m;i--){
//		N[n]&=N[i];
//		cout<<N[i]<<'\n';
		long long sum=N[i];
		for(int j=0;j<m;j++){
			sum&=N[i-j];
		}
		if(sum<ans){
			break;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
//	for(int i=1;i<=n;i++){
//		if(x[i][gw]){
////			a.insert(i);
//			a.push_back(N[i]);
//		}
//	}
	
}
