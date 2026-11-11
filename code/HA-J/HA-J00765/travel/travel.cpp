#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int a,b,c,d,e,f;
	cin>>a>>b;c=getchar();
	cin>>d>>e;f=getchar();
	cout<<(a==d)<<(a==d&&b==e)<<(a==d&&b==e&&((c<='C'&&f<='C')||(c>='D'&&f>='D')))<<
	(a==d&&b==e&&((c=='A'&&f=='B')||(c=='B'&&f=='A')||(c=='B'&&f=='C')
	||(c=='C'&&f=='B')||(c=='D'&&f=='F')||(c=='F'&&f=='D')));
}
