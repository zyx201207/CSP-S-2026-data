#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int t,x,lei=0,m=1;
	char p,q;
	
	cin>>t;
	
	for(int i=1;i<=t;i++){
		cin>>x>>p;
		lei+=x;
		if(p!=q){ 
			m+=1;
			q=p;
		}
		cout<<lei<<endl;
	}
	if(m==1) cout<<0;
	else cout<<lei/2;
	
	return 0;
}
