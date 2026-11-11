#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans,d[500005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	
	//性质A,B
	bool b=1;
	long long c=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=c){
			b=0;
			break;	
		}
	if(b){
		long long cz;
		for(int i=1;i<=n;i++){
			cz=(c+c*(i-1))*(i-1)/2;  
			if(cz<=m) ans=i;
			else break;
		}
		cout<<ans;
		return 0;
	}
	
	//暴力前9点 
	
	for(int i=1;i<=n;i++){   //以a[i]为基准计算 
		long long sum=0,k=i,cnt=0; 
		 
		for(int j=1;j<i;j++){
			d[j]=a[i]-a[j];  //操作次数 
			sum+=d[j];
		}
		while(sum>m){
			k--;
			sum-=d[++cnt];  //去掉损失大的 
		}
		ans=max(k,ans);
	}
	cout<<ans;
}
