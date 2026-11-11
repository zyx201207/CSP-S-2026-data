#include<bits/stdc++.h>
using namespace std;
string a, b;
int n[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x, y;
	cin >> x >> a >> y >> b;
	if(x==y){
		n[0]=1;
		if(a[0]==b[0]&&a[1]==b[1]){
			n[1]=1;
			if(((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(b[2]=='A'||b[2]=='B'||b[2]=='C'))||((a[2]=='D'||a[2]=='E')&&(b[2]=='D'||b[2]=='E'))){
				n[2]=1;
				if(a[2]=='A'&&b[2]=='B') n[3]=1;
				if(a[2]=='B'&&b[2]=='A') n[3]=1;
				if(a[2]=='B'&&b[2]=='C') n[3]=1;
				if(a[2]=='C'&&b[2]=='B') n[3]=1;
				if(a[2]=='D'&&b[2]=='E') n[3]=1;
				if(a[2]=='E'&&b[2]=='D') n[3]=1;
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout << n[i];
	}
	return 0;
}
