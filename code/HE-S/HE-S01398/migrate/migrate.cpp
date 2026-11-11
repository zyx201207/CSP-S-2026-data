#include<bits/stdc++.h> 
using namespace std;
int n;//n水晶数量 m操作数 
long long a[500010],st[500010],sum[500010],m;
int value(int x){//绝对值 
	if(x<0) return -x;
	else return x;
}
int main(){
	//freopen("crystal.cpp","r",stdin);
	//freopen("crystal.cpp","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1);
	st[1]=0;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];//前缀和 
		if(i>1) st[i]=a[i]-a[i-1]+st[i-1];//差分数组	
	}
	if(n>5000){
		bool flag=0;
		for(int i=2;i<=1e4;i++){
			if(st[i]-st[i-1]!=st[2])flag=1;
		}
		if(!flag) cout<<m/value(st[2])+1<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cout<<sum[i]<<" ";
//	}
//	cout<<endl;
//	for(int i=1;i<=n;i++){
//		cout<<st[i]<<" ";
//	}
//	cout<<endl;
	int l=1,r=2;
	int ans=0;
	while(r<=n){
		if(st[r]-st[l-1]>m){
			l++;
		//	cout<<l<<" "<<r<<" "<<"l++"<<endl; 
		}
		for(int i=0;i<=m;i++){
			if((sum[r]-sum[l-1]+i)%(r-l+1)==0){
				ans=max(ans,r-l+1);
		//		cout<<sum[r]<<" "<<sum[l-1]<<" "<<r-l+1<<endl;
		//		cout<<l<<" "<<r<<" "<<i<<" %%"<<endl;
				break;
			}
		}
		r++;
	}
	
	if(n==1) cout<<1<<endl;
	else cout<<ans<<endl;
	
	return 0;
}
