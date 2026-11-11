#include <bits/stdc++.h> 
using namespace std;
int n;
long long m;
long long x[500005];//原来的值 
long long y[500005];//前后差值 
long long z[500005];//前缀和差值 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	
	cin>>n>>m;//水晶的数量  最多操作次数 
	for(int i=1;i<=n;i++){//原来的值
		cin>>x[i];
	}
	sort(x+1,x+1+n);
	for(int i=1;i<=n-1;i++){//前后差值 n-1个
		y[i]=x[i+1]-x[i];//差值 
		z[i]=y[i]+z[i-1];//差值前缀和 
	} 
	n--;//差值个数 
	long long ans;
	for(int t=0,w=n;t<=w;){//二分查找 
		ans=(t+w)/2;//取中间值 
		if(t+1==w){//找到结果 
			ans=t;
			break;
		}
		int f=0; //是否可以做到 
		long long sum=0;
		for(int i=1;i<=ans;i++){
			sum+=y[i]*i;
		}
		if(sum<=m){
			f=1;
		}
		for(int j=2;j+ans-1<=n;j++){
			sum-=z[j+ans-2]-z[j-2];
			sum+=y[j+ans-1]*ans;
			if(sum<=m){//可以做到 
				f=1;
				break;
			}
		}
		if(f==1){
			t=ans; //头更新 
		}else{
			w=ans;//尾更新 
		}
	}
	cout<<ans+1;
	return 0;
}
//终 
