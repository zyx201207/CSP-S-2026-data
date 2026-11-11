#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	int x=(c[0]-48)*10+(c[1]-48),y=(d[0]-48)*10+(d[1]-48);
	char x1=c[2],y1=d[2];
	bool a1,b1,c1,d1;
	if(a==b)a1=1;
	if(a1)if(x==y)b1=1;
	if(b1){
		if(x1=='A'||x1=='B'||x1=='C'){
			if(y1=='A'||y1=='B'||y1=='C')c1=1;
		}else{
			if(y1=='D'||y1=='F')c1=1;
		}
	}
	if(c1){
		if(x1=='A'&&y1=='B')d1=1;
		if(x1=='B'&&y1=='A')d1=1;
		if(x1=='B'&&y1=='C')d1=1;
		if(x1=='C'&&y1=='B')d1=1;
		if(x1=='D'&&y1=='E')d1=1;
		if(x1=='E'&&y1=='D')d1=1;
	}
	cout<<a1<<b1<<c1<<d1;
	return 0;
}

