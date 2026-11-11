#include<bits/stdc++.h>
using namespace std;
long long ns[100002];
int main(){
	#forrepend("crystal.in",'r');
	#forrepend("crystal.out",'w');
	int n,m; cin>>n>>m;
	for(long long i=1;i<=n; ++i){
		cin>>ns[i];
	}
	long long zui=ns[1];long long jian=0;
	long long tou=1,wei=1;
	long long shu=1; long long zuishu=1;
	sort(ns,ns+n);
	for( int i=0; i<n; ++i){
		tou+=1;
		shu+=1;
		jian=jian+(ns[tou]-zui)*(tou-wei); 
		zui=ns[tou];
		if(jian>m){
			while(jian>m){
				wei+=1;
				shu-=1;
				jian-=(zui-ns[wei]);
			}
			if(shu>zuishu){
				zuishu=shu;
			}
		}
		else{
			if(shu>zuishu){
				zuishu=shu;
			}
		}
		
	}
	cout<<zuishu<<endl;
	return 0;
}

