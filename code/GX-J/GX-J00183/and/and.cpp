#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int sent(int x){
	int ans=0;
	for(int i=2;i<=x;i*=2){
		ans++;
		if(x==i){
			return 1;
		}
	}
	return 0;
}
int maxn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(sent(a[i]+1)==0){
			flag=0;
		}
			
	}
	sort(a+1,a+n+1);
	if(flag){
		cout<<a[n-m+1];
	}else if(sent(n)==1){
		int sum=a[n];
		for(int i=n;i>=n-m+1;i--){
			sum&=a[i];
		}
		cout<<sum;
	}else{
		if(m==1){
			cout<<a[n];
		}else if(m==2){
			for(int i=1;i<=n;i++){
				int sum=a[i];
				for(int j=i+1;j<=n;j++){
					sum&=a[j];
					maxn=max(sum,maxn);
				}
			}
			cout<<maxn;
		}else{
			cout<<a[n-m+1];
		}
	}
		
	return 0;
}
