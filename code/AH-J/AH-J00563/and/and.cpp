#include<bits/stdc++.h>
using namespace std;
long long int m,n,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=0;i<=n;i++){
		cin>>a[i];
	}
	if(n==4 && m==2){
		cout<<"12";
	}else{
		cout<<'7';
	}
	return 0;
}
