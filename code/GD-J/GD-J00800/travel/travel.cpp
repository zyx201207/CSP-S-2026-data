#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	string a1,a2,b1,b2;
	cin>>a1>>a2>>b1>>b2;
	int res0=(a1==b1); 
	cout<<res0;
	int res1=0;
	if(res0)res1=(a2[0]==b2[0]&&a2[1]==b2[1]);
	cout<<res1;
	int id1=a2[2],id2=b2[2];
	if(res1){
		cout<<((id1=='A'&&id2=='B')
		||(id1=='A'&&id2=='C')
		||(id1=='B'&&id2=='A')
		||(id1=='B'&&id2=='C')
		||(id1=='C'&&id2=='B')
		||(id1=='C'&&id2=='A')
		||(id1=='D'&&id2=='F')
		||(id1=='F'&&id2=='D'))
		;
	}
	else cout<<0;
	if(res1){
		cout<<((id1=='A'&&id2=='B')
		||(id1=='B'&&id2=='A')
		||(id1=='B'&&id2=='C')
		||(id1=='C'&&id2=='B')
		||(id1=='D'&&id2=='F')
		||(id1=='F'&&id2=='D'))
		;
	}
	else cout<<0;
} 
