#include<bits/stdc++.h>
using namespace std;
int a,b,i,j,xx,yy;
string x,y;
int main(){
	freopen("D://GD-J03240//travel//travel.in","r",stdin);
	freopen("D://GD-J03240//travel//travel.out","w",stdout);
	cin>>a>>x>>b>>y;
	if(a==b){
		cout<<1;
		i=x[0]*10;
		j=x[1];
		xx = i+j;
		i=y[0]*10;
		j=y[1];
		yy = i+j;
		if(xx==yy){
			cout<<1;
			if((x[2]=='A' || x[2]=='B' || x[2]=='C') && (y[2]=='A' || y[2]=='B' || y[2]=='C')){
				if(x[2]=='B' || y[2]=='B')cout<<"11";
				else cout<<"10";
			}
			else if((x[2]=='D' || x[2]=='F') && (y[2]=='D' || x[2]=='F')){
				cout<<"11";
				return 0;
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
