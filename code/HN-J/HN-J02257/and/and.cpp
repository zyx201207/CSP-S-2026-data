#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long a,b,i,y,p,c;
	cin>>a>>b;
	p=0;
	for(a=a;a>0;a--){
		cin>>i>>y;
	    c=p;
		p=i and y;
		if(c>=p){
			p=c;
		}
	}
	cout<<p<<endl; 
	return 0;
}
