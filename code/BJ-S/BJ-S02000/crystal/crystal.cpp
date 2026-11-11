#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[5005];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	double ans=0;
	for(int i=0;i<n;i++){
		ans+=a[i];
	}
	ans/=n;
	int min=1e9;
	for(int i=0;i<n;i++){
		if(a[i]-ans<min){
			min=a[i]-ans;
		}
	}
	for(int i=0;i<n-1;i++){
		for(int j=0;j<n-1;j++){
			if(a[i]>a[j]){
				swap(a[i],a[j]);
			}
		}
	}
	int sum=0;
	for(int i=0;i<n;i++){
		if(abs(a[i]-min)<=m){
			sum++;
			m-=abs(a[i]-min);
		}else{
			continue;
		}
	}
	cout<<sum;
	return 0;
}
