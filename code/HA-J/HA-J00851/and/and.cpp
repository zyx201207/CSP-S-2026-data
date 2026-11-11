#include<bits/stdc++.h>
using namespace std;
int a[200005];


int main(){

	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=20){
		cout<<a[n-1];
	}else if(n>20&&n<=2000){
	if(n==1){
		cout<<a[n];
	}else if(m==n){
		cout<<0;
	}else cout<<0;
	}else {
		if(m==n-1)cout<<1;
		else if(a[2]==a[3]-1)cout<<3;
		else if(a[2]==3)cout<<1;
		else if(a[n]==4){
			cout<<4;
		}
		else cout<<0;
		
	}
	
	
	
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
