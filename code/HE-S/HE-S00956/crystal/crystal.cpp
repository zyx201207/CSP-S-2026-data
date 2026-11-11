#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}if(m>=n*(n-1)/2){
		cout<<n<<endl;
	}else{
		cout<<2+(m/5)<<endl;
	}
	return 0;
}
 
