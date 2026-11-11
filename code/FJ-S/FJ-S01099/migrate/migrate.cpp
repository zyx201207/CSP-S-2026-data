#include<bits/stdc++.h>
std::string acdegf="igrate",acdegftmp;
using namespace std;

long long main(){
	acdegftmp=acdegf+".in";
	freopen(acdegftmp.c_str(),"r",stdin);
	acdegftmp=acdegf+".out";
	freopen(acdegftmp.c_str(),"w",stdout);
	cin>>c>>t;
	if(c<=10){
		while(t--)
		solve();
	}
}

