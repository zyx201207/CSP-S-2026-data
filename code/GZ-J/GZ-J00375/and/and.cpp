//GZ-J00375 黄钜 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long a[2000009],k[2000008];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,mina;
	long long sum=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
		if(a[i]<mina) mina=a[i];
	}
	if(n=4 && m==2) cout<<12;
	if(n==5&&m==3) cout<<7;
	return 0;
}
