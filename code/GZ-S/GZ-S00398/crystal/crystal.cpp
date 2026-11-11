//GZ-S00398 ·¶Ώ£γρ 
#include <bits/stdc++.h>
#define int long long
using namespace std;

bool cmp(int x,int y){
	return x<y;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	
	int a[n+1];
	int ans[n+1];
	int more[n+1];
	//int ans=0;
	ans[1]=1;
	more[1]=m;
	//cin>>a[1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1 , a+n+1 , cmp );
	for(int i=2;i<=n;i++){
		ans[i]=1;
		more[i]=0;
	}
	
	int cnt=0;
	for(int i=2;i<=n;i++){
		int temp=0;
		if(((more[i-1]) - ((a[i]-a[i-1])*(ans[i-1])))>= 0 && more[i-1]>=0){
			ans[i]=ans[i-1]+1;
			more[i]=(more[i-1] )- ((a[i]-a[i-1])*(ans[i-1]));
			//cout<<i<<' '<<big[i]; 
			//cout<<'0';
		}
		else{
			int x=1;
			for(int j=i-1;j>=1;j--){
				temp+=(a[i]-a[j]);
				if(temp>m){
					ans[i]=x;
					more[i]=m-(temp-(a[i]-a[j]));
					break;
				}
				else if (temp==m){
					x++;
					ans[i]=x;
					more[i]=0;
					break;
				}
				else{
					x++;
				}
			}
			//cout<<'1';
		}
		cnt=max(ans[i],cnt);
	}
	
//	for(int i=1;i<=n;i++){
//		cout<<a[i]<<' ';
//		cout<<ans[i]<<' '<<more[i];
//		cout<<'\n';
//	}
	cout<<cnt;
	return 0;
}
