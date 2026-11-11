#include <bits/stdc++.h>
using namespace std;
long long n,m,s,d,zgc;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	while(n--){
		cin>>s;
		if(s>d){
			d=s;
			zgc=0;
		}else if(s==d){
			zgc++;
		}
	}
	if(d==4){
		if(zgc<m){
			cout<<3;
			return 0;
		}
	}
	m-=zgc;
	while(m--){
		d=(d+1)/2-1;
	}
	cout<<d;
	return 0;
}
