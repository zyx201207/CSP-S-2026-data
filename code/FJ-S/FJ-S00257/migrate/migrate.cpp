#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	int a,b;
	cin>>a>>b;
	for(int i=1;i<=b;i++)cout<<rand()%9999+1;
	return 0;
} 
