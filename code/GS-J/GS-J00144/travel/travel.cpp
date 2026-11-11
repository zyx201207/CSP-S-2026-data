#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.out","w",stdout);
	freopen("travel.in","r",stdin);
	int a,b,c,d;
	string r1,x1;
	char r2[5],x2[5];
	cin>>r1;
	for (int i=0;i<3;i++){
		cin>>r2[i];
	}
	cin>>x1;
	for (int i=0;i<3;i++){
		cin>>x2[i];
	}
	if (r1==x1){
		a=1;
	}
	else{
		a=0;
	}
	if (r2[0]+r2[1]==x2[0]+x2[1]){
		b==1;
		if (r2[3]=='A' && x2[3]=='B'){
			c==1;
			d==1;
		}
		if (r2[3]=='A' && x2[3]=='C'){
			c==1;
		}
		if (r2[3]=='B' && x2[3]=='A'){
			c==1;
			d==1;
		}
		if (r2[3]=='B' && x2[3]=='C'){
			c==1;
			d==1;
		}
		if (r2[3]=='C' && x2[3]=='B'){
			c==1;
			d==1;
		}
		if (r2[3]=='C' && x2[3]=='A'){
			c==1;
		}
		if (r2[3]=='D' && x2[3]=='F'){
			c==1;
			d==1;
		}
		if (r2[3]=='F' && x2[3]=='D'){
			c==1;
			d==1;
		}
		else{
			c==0;
			d==0;
		}
	}
	else{
		b==0;
	}
	cout<<a<<b<<c<<d;
	fclose(stdout);
	fclose(stdin);
	return 0;
}
