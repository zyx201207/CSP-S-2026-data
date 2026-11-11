#include<bits/stdc++.h>
using namespace std;
int a[200050];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,n1,k,w=0,ans=0;
	bool pan=1;
	cin>>n>>m;
	n1=n;
	for(int i=1;i<=n;i++){
	cin>>a[i];
	}
	sort(a+1,a+n+1);
	k=a[n];
	while(n1>1){
	if(n1%2==1){
	pan=0;
	break;
	}
	n1=n1/2;
	}
	if(m==1){
	cout<<a[n];
	return 0;
	}
	if(m==2||m==n){
	cout<<a[n];
	return 0;
	}
	if(pan==1){
	cout<<n-m;
	return 0;
	}
	while(k>1){
	k=k/2;
	w++;
	}
	w--;
	for(int i=1;i<=w;i+=2){
	ans=ans+pow(2,i);
	}
	cout<<ans;
	return 0;
}

