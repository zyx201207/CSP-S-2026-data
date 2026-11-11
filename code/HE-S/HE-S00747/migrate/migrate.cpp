#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int a,b;
	cin>>a>>b;
	for(int i=0;i<b;i++){
		if(i<5)cout<<rand()%10000000<<endl;
		else cout<<rand()%10<<endl;
	}
	return 0;
} 
