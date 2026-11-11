#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	int cha[1000];
	int z=0;
	int a[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	
	for(int i=1;i<=n;i++){
		if(n==1){
			cout<<1<<endl;
			return 0;
		}
		else if(n==2&&a[i]==a[i+1]){
			cout<<2<<endl;
			return 0;
		}
		else if(a[i+1]-a[i]>m){
			cout<<0<<endl;
			return 0;
		}
	}
	return 0;
}
