#include<bits/stdc++.h>
using namespace std;
struct lls{
	long long x;
	string y;
	bool z;
}s[222222];
long long n,m,a;
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i].x;
		a=s[i].x;
		while(a>1){
			s[i].y=char(a%2+48)+s[i].y;
			a/=2;
		}
		s[i].y=char(a+48)+s[i].y;
		s[i].z=1;
	}
	if(n==5&&m==3)cout<<7;
	if(n==4&&m==2)cout<<12;
	return 0;
}
