#include<bits/stdc++.h>
using namespace std;
long long n,i,num[10001][35],a[35],no[100001],m,dp[1001],maxn=0;
void turn(int x,int pos){
	for(int i=35;i>=1;i--){
		if(x>=a[i]){
			num[pos][i]=1;
			x-=a[i];
		}
	}
}
long long V(int a1,int b){
	long long ans;
	for(int i=35;i>=1;i--){
		if(num[a1][i]&&num[b][i]){
			ans+=a[i];
		}
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	a[1]=1;
	for(int i=2;i<=35;i++){
		a[i]=a[i-1]*2;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>no[i];
		maxn=max(maxn,no[i]);
	}
	sort(no+1,no+n+1);
	for(int i=1;i<=n;i++){
		turn(no[i],i);
	}
	for(int i=n;i>0;i--){
		if(i==m){
			cout<<no[i];
			break;
		}
	}
	return 0;
} 
