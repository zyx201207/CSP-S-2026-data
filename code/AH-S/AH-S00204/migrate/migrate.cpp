#include<bits/stdc++.h>
using namespace std;
long long c,t,k,l,s,cha;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(long long i=0;i<t;i++){
		cin>>k>>s;
		for(long long j=0;j<c;j++){
			cin>>l;
			if(j+1!=c){
				k=l;
			}
		}
		cha=l-k;
		if(s==cha||(s-1)>=cha*k){
			cout<<0;
		}else{
			cout<<s/(k*cha);
		}
	}
	return 0;
}
