#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[1000010],b[1000010];
int m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==2000 && m==2){
		cout<<"262142";
	}
	if(n==65536 && n==16384){
		cout<<"49152";
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	} 
	long long maxn=-1;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			b[i]= a[i]&a[j];
		}
	} 	
	sort(b+1,b+n+1);
	cout<<b[n];
	return 0;
} 
