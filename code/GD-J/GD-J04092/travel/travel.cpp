#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y,n,m,sum=0;
	char a,b;
	cin>>x>>y>>a>>n>>m>>b;
	if((x==n&&x!=1)&&x!=16){
		cout<<"1";
		sum+=1;
	}
	else
	cout<<"0";
	if(y==m&&sum!=0){
		cout<<"1";
	}
	else
	cout<<"0";
	if(sum!=0&&((a=='A'&&b=='C'||'B')||(a=='B'&&b=='C'||'A')||(a=='C'&&b=='A'||'B')||(b=='D'&&a=='F')||(a=='F'&&b=='D'))) {
		cout<<"1";
	}
	else
	cout<<"0";
	if((a=='A'&&b=='B')||(a=='B'&&b=='C')||(a=='D'&&b=='F')){
		cout<<"1";
	}
	else
	cout<<"0";
	
	return 0;
}
