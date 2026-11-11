#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int s[10010]={0};
	while(t){
		int a,b;
		cin>>a>>b;
		for(int i=1;i<=a;i++){
			cin>>s[i];
		}
		if(a%2==0&&b%2==0){
			cout<<1;
			continue;
		}
		if(a%2!=0&&b%2==0){
			cout<<2;
			continue;
		}
		if(a%2==0&&b%2!=0){
			cout<<3;
			continue;
		}
		if(a%2!=0&&b%2!=0){
			cout<<0;
			continue;
		}
	}
	return 0;
}
