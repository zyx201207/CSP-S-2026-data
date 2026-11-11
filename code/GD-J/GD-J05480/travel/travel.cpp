#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	string s="0000";
	char p[5]={'A','B','C','D','F'};
	int x,y;
	if(a==c){
		s[0]='1';
		if(b[0]==d[0]&&b[1]==d[1]){
		s[1]='1';
		for(int i=0;i<5;i++){
			if(b[2]==p[i]){
				x=i;
			}
			if(d[2]==p[i]){
				y=i;
			}
		}
		if((x<=3&&y<=3)||(x>=4&&y>=4)){
			s[2]='1';
			if(x-y==1||y-x==1){
				s[3]='1';
			}
		}
	}
	}
	cout<<s;
	return 0;
} 
