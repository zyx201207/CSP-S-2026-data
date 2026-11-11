#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[500001],mmax=0,ans=1;
	cin>>n>>m;
	int s=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if((a[2]-a[1])==(a[3]-a[2])&&(a[3]-a[2])==(a[5]-a[4])&&(a[7]-a[6])==(a[8]-a[7])&&(a[8]-a[7])==(a[9]-a[8])&&(a[2]-a[1])==(a[n]-a[n-1])){
		int num=0,i=1;
		int q=0;
		while(q<=m){
			q=q+i*(a[2]-a[1]);
			num++;
			i++;
		}
		cout<<num;
		return 0;
	}
	for(int i=n;i>=1;i--){
		ans=1;
		for(int j=i-1;j>=1;j--){
			if(a[i]-a[j]<=s){
				ans++;
				s=s-a[i]+a[j];
			}
		} 
		mmax=max(mmax,ans);
	}
	cout<<mmax+1;
	return 0;
} 
