#include<bits/stdc++.h>
using namespace std;
int main(){
	frepoen("travel.in","r",stdin);
	frepoen("travel.out","w",stdout);
	int a,b,f;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)
		cout<<"1";
	for(int i=0;i<2;i++){
		if(c[i]==d[i]){
			f=1;
		}
	}	
	if(f==1)
		cout<<"1";
	cout<<"00";
	return 0; 
} 
