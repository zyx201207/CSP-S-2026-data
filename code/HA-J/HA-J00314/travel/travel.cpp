#include<bits/stdc++.h>
#define ll long long
using namespace std;
//是否在同一节车厢；是否在同一节车厢的同一排；是否在同一节车厢的同一排，且位于过道的同一侧；是否相邻。
string x,y,n,m;
bool chexiang,pai,ce;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>x>>m>>y;
	if(n==m){
		cout<<1;
		chexiang=true;
	}
	else{
		cout<<0;
		chexiang=false;
	}
	if(chexiang){
		if(x[0]==y[0] && x[1]==y[1]){
			pai=true;
			cout<<1;
		}
		else{
			pai=false;
			cout<<0;
		}
	}
	else{
		cout<<0;
		pai=false;
	}
	if(chexiang && pai){
		if(((x[2]<='B' && x[2]>='A') && (y[2]<='B' && y[2]>='A')) || ((x[2]>='C' && x[2]<='F') && (y[2]<='F' && y[2]>='C'))){
			cout<<1;
			ce=true;
		}
		else{
			ce=false;
			cout<<0;
		}
	}
	else{
		cout<<0;
		ce=false;
	}
	if(chexiang && pai && ce){
		if((x[2]=='A' && y[2]=='B') || (x[2]=='B' && y[2]=='A') || (y[2]=='D' && (x[2]=='C' || x[2]=='F')) || (x[2]=='D' && (y[2]=='C' || y[2]=='F'))){
			cout<<1;
		}
	}
	else cout<<0;
	return 0;
}

// Trick||Treat!

