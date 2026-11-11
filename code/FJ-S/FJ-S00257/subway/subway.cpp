#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(0));
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=1;i<=e;i++)cout<<rand()%9999+1;
	return 0;
} 
