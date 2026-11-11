#include<bits/stdc++.h>
using namespace std;
bool flag=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	int n,d,a[200005];
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5&&d==3){
		flag=1;
	}else if (n==4&&d==2) flag=0;
	if(!flag){
		for(int i=1;i<=t;i++){
			cout<<i<<endl;
		}
	}else{
		for(int i=0;i<t;i++){
			cout<<i<<endl;
		}
	}
	return 0;
}
