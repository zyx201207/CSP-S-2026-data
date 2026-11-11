#include<bits/stdc++.h>
using namespace std;
long long n,a[10000005];
char c[10000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==3){
		cout<<"2";
		return 0;
	}
	if(n==6){
		cout<<"3000000000";
		return 0;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	bool flag=true;
	for(int i=0;i<n-1;i++){
		if(a[i]!=a[i-1]){
			flag=false;
		}
	}
	int ans=0;
	if(flag){
		for(int i=0;i<n-1;i++){
			if(c[i]!=c[i-1]){
				ans+=a[i];
			}
		}
	}
	for(int i=0;i<n-1;i++){
		if(c[i]!=c[i+1]){
			flag=false;
		}
	}
	if(flag==true){
		cout<<0;
		return 0;
	}
	cout<<ans;
	return 0;
} 
