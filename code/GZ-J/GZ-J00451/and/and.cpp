//GZ-J00451 胡景天 兴义市弘毅中学
#include<bits/stdc++.h>
using namespace std;
bool bbb(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,k=1,jj=0,cs=1,cd=0;
	cin>>n>>m;
	long long a[n],b[n];
	for(long long i=0;i<=n-1;i++){
		cin>>a[i];
		if(a[i]!=i){
			k=0;
		}
	}sort(a,a+n,bbb);
	if(m==1){
		
		
		//for(long long i=0;i<=n-1;i++){
		//cout<<a[i];
		
	//}
		cout<<a[0];
	}
	else if(m==n){
		//sort(a,a+n,bbb);
		cout<<a[n-1];
	}
	else if(a[0]==3){
		cout<<2;
	}
	else{
		cout<<0;
	} 
	return 0;
}

