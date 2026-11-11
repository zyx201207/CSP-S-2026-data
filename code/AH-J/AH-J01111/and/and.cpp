#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],sum=0,maxn=0;
bool cmp(int x,int y){
	if(x>y)return 1;
	return 0;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
		sort(a,a+n,cmp);
		cout<<a[0];
		return 0;
	}
	if(m==n){
		sort(a,a+n,cmp);
		sum=a[0];
		for(int i=1;i<n;i++)sum=(a[0]&sum);
		cout<<sum;
		return 0;
	}
	if(m==2){
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}
		cout<<maxn;
		return 0;
	}
	sort(a,a+n,cmp);
	sum=a[0];
	for(int i=1;i<m;i++)sum=(a[i]&sum);
	cout<<sum;
	return 0;
}
