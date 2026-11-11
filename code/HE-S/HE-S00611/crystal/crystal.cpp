#include<bits/stdc++.h>
using namespace std;
int n[10000]; 
int main(){
	freopen("crystal.in","r",stdin)
	freopen("crystal.in","w",stdout)
	int n,m,a,s;
	cin>>n>>m;
	cin>>a;
	for(int j=1;j>=0;j--){
		for(int i=1;i>=0;i--){
			i-=j;
			j+=i;
			s=j+i;
			cout<<s<<endl;
		}
		
		}
		
	return 0;}

