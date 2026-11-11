#include<bits/stdc++.h>
using namespace std;
#define ll long long
char a[100000000],b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int  k=1,n;
	cin>>n; 
	for(int i=1;i<=n;i++){
		int s;
		cin>>s>>b;
		for(int j=1;j<=s;j++,k++){
			a[k]=b;
			//cout<<a[k]<<' '; 
		}
	}
	int sum=0;
	//for(int i=1;i<=k;i++)  cout<<a[i]; 
	for(int i=1;i<=k/2;i++){
		if(a[i]!=a[k-i]){
			//cout<<a[i]<<' '<<k-i ; 
		 	sum++; 
		}\
	}
	cout<<sum;
	return 0; 
	//sbccf t2出那么难干吗 
}
