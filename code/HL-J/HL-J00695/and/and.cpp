#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
long long ans;
long long check(int s){
	long long ans=a[s];
	for(int i=1;i<m;i++){
		ans=ans&a[s+i];
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	long long ans_1=-1;
	long long ans_2;
	cin>>a[1];
	ans_1=a[1];
	ans_2=ans_1;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		ans_1=max(ans_1,a[i]);
		ans_2=ans_2&a[i];
	}
	if(n<=20){
		sort(a+1,a+n+1);
		long long ans=-1;
		do{
			long long ans1=a[1];
			for(int i=2;i<=m;i++){
				ans1=ans1&a[i];
			}
			ans=max(ans,ans1);
		}while(next_permutation(a+1,a+n+1));
		cout<<ans;
		return 0;
	}
	if(m==1) {
		cout<<ans_1;
		return 0;
	}
	if(m==n) {
		cout<<ans_2;
		return 0;
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
//3 15 12 12