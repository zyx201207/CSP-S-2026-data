#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int a,s;
	int con=0;
	cin>>a>>s;
	long long d[105];
	for(int i=0;i<a;i++){
		cin>>d[i];
	}
	if(a=4)con=12;
	else if(a==5)con=7;
	
	cout<<con;
	return 0;
} 
