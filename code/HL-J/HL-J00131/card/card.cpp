#include<bits/stdc++.h>
using namespace std;
long long n,m;
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	long long a[m];
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	sort(a,a+n+1); 
	for(int i=1;i<=m;i++){
		 if(a[i]==a[i-1]){
		 	cout<<i<<" ";
		 	a[i-1]=max(a[i],a[i]+n+1);
		 }
	}
	return 0;
}
