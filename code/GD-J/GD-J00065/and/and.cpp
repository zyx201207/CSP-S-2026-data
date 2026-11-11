#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005][45],n,k,x[200005],m_cnt,b[200005],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1,greater<int>());
	for(int i=1;i<=n;i++){
		int t=x[i],cnt=0;
		while(t){
			a[i][++cnt]=(t&1);
			t/=2; 
		}
		m_cnt=max(m_cnt,cnt);
	}
//	cout<<m_cnt<<"\n";
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=4;j++){
//			cout<<a[i][j]<<" ";
//		}
//		cout<<"\n";
//	}
	for(int i=m_cnt;i>=1;i--){
		bool f=0;
		for(int l=1;l<=n;l++){
			if(a[l][i]==1){
				ans++;
				b[ans]=x[l];
			}
			if(ans==k){
				f=1;
				break;
			}
		}
		if(f==0) ans=0;
		else break;
	}
	if(ans<k){
		cout<<0;
		return 0;
	}
	int sum=b[1];
	for(int i=2;i<=ans;i++){
		sum&=b[i];
	}
	cout<<sum;
	return 0;
}
/*
5 3
31 3 1 15 7
*/

