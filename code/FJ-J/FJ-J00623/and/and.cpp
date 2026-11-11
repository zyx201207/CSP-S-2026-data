#include<bits/stdc++.h>
using namespace std;
long long m,n,a[200005],b=INT_MIN,c=INT_MAX;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>b){
			b=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<c){
			c=a[i];
		}
	}
	if(m==1){
		cout<<b;
	}
	else if(m==2){
		cout<<b%c;
	}
	else if(m==n){
		cout<<"1";
	}
	else{
		cout<<b%c;
	}
	return 0;
}