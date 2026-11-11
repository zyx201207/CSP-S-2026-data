#include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int &x,int&y){
	return x<y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	vector<int>a(n+1);
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end(),cmp);
	int ans=0;
	int sum=0;
	int mx=0;
	for(int i=1;i<=n;i++){
		int	cnt=n/2+1;
		if(a[i]>a[cnt])continue;
		if(a[i]==a[cnt])sum++;
		for(int j=1;j<=m;j++){
			 if(a[i]<a[cnt]){
				mx=	a[cnt-i]++;
			
			if(mx==a[cnt]){
				ans+=1;
				}
			}
		}
		
	}
	ans+=1;
	cout<<ans+sum;
	
	return 0;
} 




