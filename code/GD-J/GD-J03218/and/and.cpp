#include<bits/stdc++.h>
using namespace std;
long long a[200005],b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,max1=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(max1<a[i]){
			max1=a[i];
		}
	}
	if(m==1){
		cout<<max1;
		return 0;
	}
	if(m==2){
		max1=-1;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				max1=max(max1,(a[i]&a[j]));
			}
		}
		cout<<max1;
		return 0;
	}
	if(m==n){
		max1=a[0];
		for(int i=1;i<n;i++){
			max1=(max1&a[i]);
		}
		cout<<max1;
		return 0;
	}
	if(m==n-1){
		max1=a[0];
		for(int i=1;i<n-1;i++){
			b[i]=max1;
			max1=(max1&a[i]);
		}
		cout<<max1;
		return 0;
	}
	cout<<0;
	return 0;
}
