#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],c,ans,f[500005];
int turn1(int l1,int r1){//将a到b变成b的代价o(n) 
	long long t=0;
	for(int i=l1;i<r1;i++){
		t+=a[r1]-a[i];
	}
	return t;
}
int turn(int l1,int r1){//优化算法，o(1)求代价 
	long long t=0;
	t=f[r1]-f[l1]-(l1-1)*(r1-l1);
	return t;
}
bool check(int k){//能不能合成k个 ,k<=n-1
	//滑动窗口o（n）枚举 
	//cout <<k<<"!!!!!!!!!";
	for(int i=k;i<=n;i++){
		//cout << i-k+1<<" "<<i<<" "<<turn(i-k+1,i)<<endl;
		if(turn(i-k+1,i)<=m){
			return 1;
		}
	}
	return 0;
	
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n>>m;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		
	}
	sort(a+1,a+n+1);
	f[1]=0;
	for(int i=2;i<=n;i++){
		f[i]=f[i-1]+(i-1)*(a[i]-a[i-1]);
		
	}
	long long l=1,r=n,mid;//二分答案
	while(l<=r){
		mid=(l+r)/2;
		if(check(mid)){//尝试更大 
			ans=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	/*for(int i=l;i<=r;i++){
		if(!check(i)){//尝试更大 
			ans=i-1;
			break;
			
		}
	}*/
	cout <<ans;//<<check(3970)<<check(3845);
	//cout <<check(4);
	
	return 0;
}
