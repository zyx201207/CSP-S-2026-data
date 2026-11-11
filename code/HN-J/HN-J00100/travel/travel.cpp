#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000][1000],qp,dx[6]={0,1,0,-1},dy[6]={1,0,-1,0},acx,awz,aps,bcx,bwz,bps,bj=0;

int cl(string x){
	int len=sizeof(a);
	int cx=(x[0]-'0')*10+x[1]-'0';
	return cx;
}
int js(string x){
	int wz=(x[0]-'0')*10+x[1]-'0';
	int ps=x[2]-'A'+1;
	if(bj=0){
		
		awz=wz;
		aps=ps;
	}
	else {
		bwz=wz;
		bps=ps;
	}bj++;
}
int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,aw,bw;
	cin>>a>>aw>>b>>bw;
//	cout<<aw[2]<<endl;
	acx=cl(a);
	bcx=cl(b);
	aps=(aw[0]-'0')*10+aw[1]-'0';
	bps=(bw[0]-'0')*10+bw[1]-'0';
awz=aw[2]-'A'+1;bwz=bw[2]-'A'+1;
	if(acx==bcx){
		cout<<1;
		if(aps==bps){
			cout<<1;
			if((awz<=3&&bwz<=3)||(awz>3&&bwz>3)){
				cout<<1;
				if((max(awz,bwz)-min(awz,bwz))==1)cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<"00"; 
	}
	else {
		for(int i=0;i<=3;i++){
			cout<<0;
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
