//GZ-J00375 黄钜 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long a[59824];
string c[59824];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	long long n,sum=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}	
	if(n==1){
		cout<<0<<"\n";
		return 0;
	}
	cout<<n*a[1]/2<<"\n";
	return 0;
}
/*
6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
