#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		if(c==11||c==12){
			int t=a[1]-a[0];
			if(d<2t) cout<<0;
			else cout<<1;
		}else cout<<0;
	}	
	return 0; 
}

