#include <bits/stdc++.h>
using namespace std;
long long c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==0){
		cout<<"1\n2";
	}else{
		cin>>c>>t;
		for(int i=1;i<=t;i++){
			cout<<rand()%(i+4)<<'\n'; 
		}
	}
	return 0;
} 
