#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n],d[n][n],dx;
	bool b=1;
	memset(d,-1,sizeof(d));
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==1)dx=a[1]-a[0];
		if(i>=1){
			if((a[i]-a[i-1])!=dx){
				b=0;
			}
		}
	}
//	cout<<b<<endl;
	if(b){
//		cout<<"y"<<endl;
		int ans=1;
		long long temp=1;
		while(dx*temp<=m){
			ans++;
			temp+=ans;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a,a+n);
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++)
		{
			d[i][j]=a[i]-a[j];
		}
	}
//	for(int i=1;i<n;i++){
//		for(int j=i-1;j>=0;j--){
//			cout<<d[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	int ans=1; 
	for(int i=1;i<n;i++){
		int tm=m,tans=1;
		for(int j=i-1;j>=0;j--){
			if(tm>=d[i][j]){
				tm-=d[i][j];
				tans++;
			}
			else break;
		}
		ans=max(ans,tans);
	}
	cout<<ans<<endl;
	return 0;
}
//暴力倾向严重（） 
