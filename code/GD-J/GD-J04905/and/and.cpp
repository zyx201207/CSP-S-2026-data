#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,maxnn;
int a[N];
int b[2*N];
bool flag[N];
bool cmp(int x,int y){
	return x>y;
}
void dfs(int deep,int sum){
	if(deep>m){
		maxnn=max(maxnn,sum);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==true)continue;
		flag[i]=true;
		dfs(deep+1,sum&a[i]);
		flag[i]=false;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
	}else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				int sum=a[i]&a[j];
				maxn=max(sum,maxn);
			}
		}
		cout<<maxn;
	}else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
	}else if(m==n-1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			b[i]=a[i];
			b[i+n]=a[i];
		}
		for(int i=1;i<=n;i++){
			int sum=b[i];
			for(int j=i;j<i+n-1;j++){
				sum=sum&b[j];
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
	}else{
		dfs(1,2147483647);
		cout<<maxnn;
	}
	return 0;
}
