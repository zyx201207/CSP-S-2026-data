#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n,m;
	string A,B;
	cin>>n>>A>>m>>B;
	if(n==m) cout<<"1";
	else cout<<"0";
	
	int pai_a=(A[0]-'0')*10+(A[1]-'0');
	int pai_b=(B[0]-'0')*10+(B[1]-'0');
	if(pai_a==pai_b&&n==m) cout<<"1";
	else cout<<"0";
	
	char s1=A[2],s2=B[2];
	if((s1=='D'&&s2=='C')||(s1=='C'&&s2=='D')) cout<<"0";
	else if(pai_a==pai_b&&n==m) cout<<"1";
	else cout<<"0";
	
	if(((s1=='A'&&s2=='B')||(s1=='B'&&s2=='A'))||
	((s1=='B'&&s2=='C')||(s1=='C'&&s2=='B'))||
	((s1=='D'&&s2=='F')||(s1=='F'&&s2=='D'))){
		if(pai_a==pai_b&&n==m) cout<<"1";
		else cout<<"0";
	}
	else cout<<"0";
	return 0;
}
