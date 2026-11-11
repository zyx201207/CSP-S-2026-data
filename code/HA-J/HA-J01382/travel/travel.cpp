#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,b;
	int m,v;
	cin>>n>>m>>b>>v;
	int x=int(m),c=int(v);
	if(n!=b){
		cout<<"0000";
	}else{
		if(x=c){
			cout<<"1110";
		}else{
			cout<<"1100";
		}
	}
	return 0;
}
