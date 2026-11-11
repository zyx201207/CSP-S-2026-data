#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	if(m==1){
		int maxx=0;
		for(int i=0;i<n;i++){
			cin>>a[i];
			maxx=max(a[i],maxx);
		}
		cout<<maxx;
	}
	else if(m==n){
		cin>>a[0];
		int sum=a[0];
		for(int i=1;i<n;i++){
			cin>>a[i];
			sum&=a[i];
		}
		cout<<sum;
	}
	else{
		for(int i=0;i<n;i++)  cin>>a[i];
		sort(a,a+n);
		int maxx=0;
		for(int i=0;i<n-m+1;i++){
			int sum=a[i];
			for(int j=i+1;j<i+m;j++){
				sum&=a[j];
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
	}
	return 0;
}
