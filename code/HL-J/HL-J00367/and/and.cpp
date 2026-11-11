#include<bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) fl=0;
	}	
	sort(a+1,a+n+1,greater<int>());
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==2){
		int max_1=INT_MIN;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				max_1=max(max_1,a[i]&a[j]);
			}
		}
		cout<<max_1;
		return 0;
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=i-1) fl=0;
	}
	if(fl){
		int sum=a[1];
		for(int i=2;i<=m;i++){
			sum=sum&a[i];
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
