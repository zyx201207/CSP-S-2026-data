#include<bits/stdc++.h>
using namespace std;
int a[]={1,1,1,2,2,2};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,t1,t2;
	cin>>s1>>s2>>t1>>t2;
	if(s1==t1) cout<<1;
	else{
		cout<<"0000\n";
		return 0;
	}
	if(s2[0]==t2[0]&&s2[1]==t2[1]) cout<<1;
	else{
		cout<<"000\n";
		return 0;
	}
	if(a[int(s2[2]-'A')]==a[int(t2[2]-'A')]) cout<<1;
	else{
		cout<<"00\n";
		return 0;
	}
	if((s2[2]=='A'&&t2[2]=='B')||(s2[2]=='B'&&t2[2]=='A')||(s2[2]=='B'&&t2[2]=='C')||(s2[2]=='C'&&t2[2]=='B')||(s2[2]=='D'&&t2[2]=='F')||(s2[2]=='F'&&t2[2]=='D')) cout<<1<<endl;
	else cout<<0<<endl;
	return 0;
}

