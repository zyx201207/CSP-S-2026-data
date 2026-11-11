#include<bits/stdc++.h>
using namespace std;

bool ans[5];

bool tc(char a,char b){
	map<char,int>zuiwei;
	zuiwei['A']=1;zuiwei['B']=1;zuiwei['C']=1;
	zuiwei['D']=2;zuiwei['F']=2;
	
	return (zuiwei[a]==zuiwei[b]);
}

bool xl(char a,char b){
	return (a=='D' || a=='F' || a=='B' || b=='B');
}

void CL(string ac,string az,string bc,string bz){
	if(ac==bc)
		ans[1]=true;
	else
		return;
		
	if(az[0]==bz[0] && az[1]==bz[1])
		ans[2]=true;
	else
		return;
		
	if(tc(az[2],bz[2]))
		ans[3]=true;
	else
		return;
	
	if(xl(az[2],bz[2]))
		ans[4]=true;
	else
		return;
	
	return;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	string ac,bc,az,bz;
	cin>>ac>>az>>bc>>bz;
	
	CL(ac,az,bc,bz);
	
	for(int i=1;i<=4;i++)
		cout<<ans[i];
	
	return 0;
}
