#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;int a[n],b[m+1];
	for(int i=0;i<n;i++)cin>>a[i];
	if(m==1){
		cout<<n;
	}
	else if(m==2){
		b[a[n-1]]=n;
		for(int i=n-1;i>=0;i--){
			if(a[i]!=a[n-1])b[a[i]]=i+1;
		}
		cout<<b[1]<<' '<<b[2];
	}
	else{
		for(int i=0;i<n;i++)cout<<i+1<<' ';
	}
}
