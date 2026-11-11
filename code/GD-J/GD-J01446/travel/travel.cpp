#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cr,sr,cx,sx;
	cin>>cr>>sr>>cx>>sx;
	if(cr!=cx)cout<<"0000";
	else if(sr[0]!=sx[0]||sr[1]!=sx[1])cout<<"1000";
	else if((sr[2]<='C' && sx[2]>='D')||(sr[2]>='D' && sx[2]<='C'))cout<<"1100";
	else if(sr[2]+1!=sx[2] && sr[2]-1!=sx[2])cout<<"1110";
	else cout<<"1111";
	return 0;
} 
