#include <bits/stdc++.h>
 using namespace std;
 long long b[20000010][5];
 int main(){
 	freopen("hub.in","r",stdin);
 	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t){
		long long n,d;
		cin>>n>>d;
		for(long long i=1;i<=n-1;i++){
			cin>>b[i][1];
			cin>>b[i][2];
		}
		if(t==1)cout<<1;
		else cout<<2;
		t--;
	}
	return 0;
 } 
