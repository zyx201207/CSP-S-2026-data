#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long sum;
long long ans;
long long c;
long long num;
long long now; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crtstal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	int flag=1;
	if(n==1){
		cout<<1;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	c=a[2]-a[1];
	for(int i=2;i<=n;i++){
		if(a[i]-a[i-1]!=c){
			flag=0;
			break;
		}
	}
	if(!flag){
		ans=1;
		for(int i=1;i<=n;i++){
			sum=0;//和 
			num=1;//多少水晶 
			 now=i-1;
			while(sum<=m&&now>=1){
				if(sum+(a[i]-a[now])<=m){
					sum+=(a[i]-a[now--]);
					num++;
				}else{
					break;
				}
			}
			ans=max(ans,num);
		}
		cout<<ans;
		return 0;
	}
	ans=1;
	sum=m;
	for(int i=n-1;i>=1;i--){
		if(sum-(a[n]-a[i])<0){
			break;
		}
		ans++;
		sum-=(a[n]-a[i]);
	}
	cout<<ans;
	return 0;
}
