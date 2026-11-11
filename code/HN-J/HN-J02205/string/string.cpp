#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	string b,f,g;
	int a,c,d,m=0,l;
	cin>>l;
	
	if(l==3){
	cin>>a>>b;
	cin>>c>>f;
	cin>>d>>g;
	
		if(l%2==0){
			
		m+=c-d+1;
		cout <<m;
		}else m=a;
			cout <<m;
	}
	
		
	if(l==2){
	cin>>a>>b;
	cin>>c>>f;
		if(l%2==0){
			if(b==f){
				cout<<0;
				return 1;
			}else m+=a+c;cout <<m;
			
		
		
		}

	}
	
	
	
	
	
	return 0;
}
