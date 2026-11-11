#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n1,m1;
	string n2,m2;
	cin>>n1>>n2>>m1>>m2;
	if(n1!=m1){
		cout<<0000;
	}
	char (n2[3]=n2[3]+1);
	else if(n2[3]==m2[3]&&n2[1]==m2[1]&&n2[2]==m2[2]){
		cout<<1111;
	}
	else if(n2[3]!=m2[3]){
		cout<<1110;
	}
	char (n2[3]=n2[3]-1);
	else if(n2[1]==m2[1]&&n2[2]==m2[2]&&m2[3]=='D'&&n2[3]=='C'||m2[3]=='C'&&n2[3]=='D'){
		cout<<1100;
	}
	else if(n2[1]!=m2[1]||n2[2]!=m2[2]){
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}