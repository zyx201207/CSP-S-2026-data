#include<bits/stdc++.h>
using namespace std;
string g,s;
int n; 
int a[200005];

int cn=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	int z=0;
	
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>g[i];
		a[i]+=a[i-1];
		
		
		for(int i=1;i<=a[i];i++){
			s[z]=g[i];
			z++;
		}
	}
	
	
	
	for(int i=0;i<=z/2;i++){
		for(int j=z-1;j>=z/2;j--){
			if(i!=j){
				cn++;
			}
		}
	}
	
	cout<<cn;
	return 0;
}
























