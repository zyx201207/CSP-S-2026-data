#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool f(){
	for(int i=1;i<=n;i++){
		if((a[i]^0)!=a[i])return false;
	}
	return true;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}else if(m==2){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,(a[i]&a[j]));
			}	
		}
		cout<<maxn;
		return 0;
	}else if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}else if(f()){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}else if(m==n-1){
		int maxn=-1,sum;
		sum=a[2];
		for(int j=3;j<=n;j++){
			sum&=a[j];
		}
		maxn=max(maxn,sum);
		sum=a[1];
		for(int j=3;j<=n;j++){
			sum&=a[j];
		}
		maxn=max(maxn,sum);
		sum=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(j==i){
					continue;
				}
				sum&=a[j];
			}
			maxn=max(maxn,sum);
		}
		cout<<maxn;
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
