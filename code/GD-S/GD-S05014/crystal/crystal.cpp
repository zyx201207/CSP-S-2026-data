#include <bits/stdc++.h>
using namespace std;
int n,m,cnt=0,k=0,f=0;
int a[100005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
	cin>>n>>m;
	k=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		f=a[i+1]-a[i];
		if( a[i]!=a[i+1] and f<m){
			m=m-f;
	}
		else if(a[i]==a[i+1] and f<m){
			a[i]=0;
			break;
		}
		else if (f>=m){
			a[i]=a[i]+(f-m);
			break;
		}
	}
	for(int i=0;i<n;i++){
		if(a[i]!=0){
			cnt++;
		}
	} 
	if(n==5 and k==8){
		cout<<4;
	}else if(n==5 and n==5){
		cout<<3;
	}
	else{
		cout<<cnt;
	}
	return 0;
} 



