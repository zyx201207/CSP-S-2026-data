#include<bits/stdc++.h>
using namespace std;
int n,m,sum,s;
int a[600000],b[600000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		
		cin>>a[i];
		if(a[i]<a[i-1]){
			sum++;
			b[sum]==a[i];
		}
	}
	for(int i=1;i<=m;i++){
		b[i]++;
		s++;	
	}	
	cout<<s/2;
}
