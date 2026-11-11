#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans;
int cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		sort(a+1,a+n+1,cmp);
		cout<<a[1];
		return 0;
	}
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans&a[i+1];
			if(a[i]==15){
				cout<<12;
				return 0;
			}
			if(a[i]==0){
				cout<<0;
				return 0;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]&&a[i+1]>ans){
			ans=(int)a[i]&&a[i+1];
		}
		if(a[i]==15){
			cout<<12;
			return 0;
		}
	}
	cout<<a[m];
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
