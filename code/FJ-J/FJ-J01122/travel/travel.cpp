#include <bits/stdc++.h> 
using namespace std;
string n,m,a,b;
int s=0,k=0,r=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>a>>m>>b;
	if(n==m)cout<<1;else{
		cout<<0;r++;	
	} 
	if(n==m&&a[1]==b[1]&&a[0]==b[0]&&r==0){
		cout<<1;
	}else {
		cout<<0;r++;
	}
	if(a[2]=='A'||a[2]=='B'||a[2]=='C')s=1;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')k=1;
	if(s==k&&r==0)cout<<1;else cout<<0;	
	if(a[2]=='A'&&b[2]=='B'||a[2]=='B'&&b[0]=='A'||a[2]=='B'&&b[2]=='C'||a[2]=='C'&&b[2]=='B'||a[2]=='D'&&b[2]=='F'||a[2]=='F'&&b[2]=='D')cout<<1;else cout<<0;	
	return 0;
}
