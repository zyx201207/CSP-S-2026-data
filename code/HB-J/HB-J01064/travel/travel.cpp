#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int line=1;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0";
		line=0;
	}
	else{
		cout<<"1";
	}
	int f=0;
	if(b[0]==d[0]&&b[1]==d[1])
	f=1;
	if(f==1&&line==1){
		cout<<"1";
	}
	else{
		cout<<"0";
		line=0;
	}
	int pa=0,pb=0;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C')
	pa=1;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')
	pb=1;
	if(line==1&&pa==pb){
		cout<<"1";
	}
	else{
		cout<<"0";
		line=0;
	}
	if(line==1&&b[2]+d[2]!='A'+'C'){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
