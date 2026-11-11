#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
string a,b,c,d;
ll q[6];
int main ( ) {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	ios::sync_with_stdio;
	cin.tie(0),cout.tie(0); 
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		q[1]=1;
		if(b[0]==d[0]&&b[1]==d[1]){
			q[2]=1;
			if((b[2]>'C')!=(!(d[2]>'C'))){
				q[3]=1;
				if(b[2]-d[2]==1||d[2]-b[2]==1)
					q[4]=1;
			}
		}
	}
	for(int i=1;i<=4;i++)
		cout<<q[i];
	return 0;
} 
