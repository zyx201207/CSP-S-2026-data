#include <bits/stdc++.h>
using namespace std;
int a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else if(m==2){
		int max=-1; 
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if((a[i] & a[j])>=max && i!=j) max=(a[i] & a[j]);
			}
		}
		cout<<max;
	}
	else if(m==n){
		int s=pow(2,21)-1;
		for(int i=1;i<=n;i++){
			s=s & a[i];
		}
		cout<<s;
	}
	else if(m==n-1){
		int max=-1;
		for(int i=1;i<=n;i++){
			int sum=pow(2,21)-1;
			for(int j=1;j<=n;j++){
				if(i!=j) sum=sum & a[j];
			}
			if(sum>=max) max=sum;
		}
		cout<<max;
	}
	return 0;
} 
