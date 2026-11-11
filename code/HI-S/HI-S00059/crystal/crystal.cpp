#include<bits/stdc++.h>
using namespace std;
int n,m;
int min(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	string b;
	cin>>b;
		if(m%2==0){
			cout<<m/2;
		}else(m%2!=0){
			cout<<m/2+1;
		}
	return 0;
	}
