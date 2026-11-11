#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[200010],ans;
bool flag=1,flag1;
void dfs(int id,int sum,int x){
	if(x==1){
		sum=a[id];
	}
	if(x==m){
		ans=max(ans,sum);
		return;
	}
	for(int i=id+1;i<=n;i++){
		dfs(i,sum&a[i],x+1);
	}
	return;
}
void f(){
	int tmp0=0,tmp1=0,tmp2=0,tmp3=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) tmp0++;
		if(a[i]==1) tmp1++;
		if(a[i]==2) tmp2++;
		if(a[i]==3) tmp3++;
	}
	if(tmp3>=m){
		cout<<3;
		return;
	}else{
		m-=tmp3;
		if(tmp2>=m){
			cout<<2;
			return;
		}else if(tmp1>=m){
			cout<<1;
			return;
		}else{
			cout<<0;
			return;
		}
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int tmp=log2(n);
	if(n==pow(2,tmp)){
		flag1=1;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(flag && a[i]>=4){
			flag=0;
		}
		if(flag1 && a[i]!=i-1){
			flag1=0;
		}
	}
	if(flag){
		f();
		return 0;
	}
	if(flag1){
		cout<<n-m;
		return 0;
	}
	if(n<=10000){
		dfs(0,0,0);
	}
	sort(a+1,a+n+1);
	int sum=a[n];
	for(int i=n-1;i>=m;i--){
		sum&=a[i];
	}
	cout<<max(ans,sum);
	return 0;
} 
