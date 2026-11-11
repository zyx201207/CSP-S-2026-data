#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200010],max_a,ans_1to5;
//CCF良心发现了？ 
//1~10 OK
//13~15 OK
bool ispow2(int x){
	if(x&(x-1)) return false;
	return true;
}
void dfs(int k,int l,int p){
	if(k==m+1){
		ans_1to5=max(ans_1to5,p);
		return ;
	}
	for(int i=l+1;i<=n;i++){
		dfs(k+1,i,p&a[i]);
	}
}
bool is13(){
	for(int i=1;i<=n;i++){
		int tmp=a[i]+1;
		if(!ispow2(tmp)) return false;
	}
	return true;
}
bool is1415(){
	if(!ispow2(n)) return false;
	for(int i=1;i<=n;i++){
		if(a[i]!=(i-1)) return false;
	}
	return true;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		max_a=max(max_a,a[i]);
	}
	if(m==1){
		//只用选一个，选最大的 
		cout<<max_a;
	}else if(m==2){
		//选2个 
		int maxandans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxandans=max(maxandans,a[i]&a[j]);
			}
		}
		cout<<maxandans;
	}else if(m==n){
		//每个都要选，没法选择，直接全部&上 
		int andans=a[1];
		for(int i=2;i<=n;i++) andans&=a[i];
		cout<<andans;
	}else if(is13()){
		//2^{k_i}-1的二进制：1...1
		//答案就是第m大的数字（从大到小选下来）
		//如：31 15 7 3 1选3个，第三个：7,31&15&7=7
		sort(a+1,a+1+n,greater<int>());
		cout<<a[m]; 
	}else if(is1415()){
		//n=8
		//0 1 2 3 4 5 6 7
		int ans=a[n];
		for(int i=n-1;i>=n-m+1;i--){
			ans&=a[i];
		}
		cout<<ans;
	}else if(n<=20){
		dfs(1,0,(1<<30)-1);//由于0&x=0，所以初始值必须全部位为1
		cout<<ans_1to5;
	}
	return 0;
}
