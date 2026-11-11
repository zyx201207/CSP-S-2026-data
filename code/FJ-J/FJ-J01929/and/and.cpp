#include<bits/stdc++.h>
using namespace std;
int n,m,num;
long long a[200005],sum;
int t(){
	int ma=-1;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			ma=max(ma,(a[i]&a[j]));
		}
	}
	return ma;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==2){
		cout<<t();
		return 0;
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	for(int i=n-1;i>n-m-1;i--){
		if(i==n-1){
			sum=a[i];
			continue;
		}
		sum=sum&a[i];
	}
	cout<<sum;
	return 0;
}
