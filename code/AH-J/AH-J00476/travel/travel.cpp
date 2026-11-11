#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int sr,sx;
	string dr,dx;
	cin>>sr>>dr>>sx>>dx;
	if(sr == sx)cout<<1;
	else cout<<0;
	if(sr == sx and dr[0] == dx[0] and dr[1] == dx[1])cout<<1;
	else cout<<0;
	if(sr == sx and dr[0] == dx[0] and dr[1] == dx[1]){
		if(dr[2] == 'A' and dx[2] == 'B')cout<<1;
		else if(dr[2] == 'A' and dx[2] == 'C')cout<<1;
		else if(dr[2] == 'B' and dx[2] == 'A')cout<<1;
		else if(dr[2] == 'B' and dx[2] == 'C')cout<<1;
		else if(dr[2] == 'C' and dx[2] == 'A')cout<<1;
		else if(dr[2] == 'C' and dx[2] == 'B')cout<<1;
		else if(dr[2] == 'A' and dx[2] == 'C')cout<<1;
		else if(dr[2] == 'D' and dx[2] == 'F')cout<<1;
		else if(dr[2] == 'F' and dx[2] == 'D')cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	if(sr == sx and dr[0] == dx[0] and dr[1] == dx[1]){
		if(dr[2] == 'A' and dx[2] == 'B')cout<<1;
		else if(dr[2] == 'B' and dx[2] == 'C')cout<<1;
		else if(dr[2] == 'B' and dx[2] == 'A')cout<<1;
		else if(dr[2] == 'C' and dx[2] == 'B')cout<<1;
		else if(dr[2] == 'D' and dx[2] == 'F')cout<<1;
		else if(dr[2] == 'F' and dx[2] == 'D')cout<<1;
		else cout<<0;
	}else{
		cout<<0;
	}
	return 0;
}
