#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	int a[1000001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==a[i-1] && a[i-1]-a[i-2]<a[i+1]-a[i]){
			m=i;
			cout<<m;
		}
		if(a[i]-a[i-1]<a[i+1]-a[i]){
			for(int k=1;k<=i;k++){
				cout<<k;
			}
		}else{
			for(int k=i;k<=m;k++){
				cout<<k-i+1;
			}
			
		}
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
