#include<bits/stdc++.h>
using namespace std;
int n,m,ans=0;
int x;
int main(){
	
	
	string s;
	freopen("card.in","r","stdin")
	freopen("card.out","w","stdout")
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(x>=ans)ans=x;
	}
	
	cout<<0;
	return 0;
}
