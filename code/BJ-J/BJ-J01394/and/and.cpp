#include<iostream>
using namespace std;
int a[200005],vis[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			if(a[i]>maxx) maxx=a[i];
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		long long sum=a[1];
		for(int i=2;i<=n;i++){
		 sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	else if(m==2){
		long long maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<n;j++){
				int sum=a[i]&a[j];
				if(sum>maxx){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
	}
	return 0;
}
