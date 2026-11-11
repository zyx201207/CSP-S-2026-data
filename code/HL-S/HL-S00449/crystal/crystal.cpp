#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
	long long a[500005]={},maxa=0,qian[500005]={},qian2[500005]={};
	long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		qian[i]=a[i]-a[i-1];
		qian2[i]=qian2[i-1]+qian[i];
	}
	long long j=1,sum=qian[2];
	for(long long i=2;;){
		if(i==n){
			cout<<maxa;
			return 0;
		}
		if(sum<=m){
			long long q=i-j+1;
			maxa=max(maxa,q);
			i++;
			sum=sum+qian[i]*q;
		}
		else{
			sum=sum-(qian2[i]-qian2[j]);
			j++;
		}
	} 
	cout<<maxa;
	return 0;
}           