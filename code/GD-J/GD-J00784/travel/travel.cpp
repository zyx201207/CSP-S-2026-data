#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
string A,B,C,D;
int X,Y;
int x,y;
int ans[5];
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> A >> B >> C >> D;
	X=((A[0]-'0')*10+(A[1]-'0'));
	x=((B[0]-'0')*10+(B[1]-'0'));
	Y=((C[0]-'0')*10+(C[1]-'0'));
	y=((D[0]-'0')*10+(D[1]-'0'));
	a=B[2];b=D[2];
	ans[0]=1;
	if(ans[0]==1 && X==Y) ans[1]=1;
	if(ans[1]==1 && x==y) ans[2]=1;
	if(ans[2]==1 && ((a=='F' && b=='D') || (a=='D' && b=='F') || (a=='A' && b=='B') || (a=='B' && b=='A') || (a=='A' && b=='C') || (a=='C' && b=='A') || (a=='C' && b=='B') || (a=='B' && b=='C'))) ans[3]=1;
	if(ans[3]==1 && ((a=='F' && b=='D') || (a=='D' && b=='F') || (a=='A' && b=='B') || (a=='B' && b=='A') || (a=='C' && b=='B') || (a=='B' && b=='C'))) ans[4]=1;
	cout << ans[1]<< ans[2] << ans[3] << ans[4];
	return 0;
}
