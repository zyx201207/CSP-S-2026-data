#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int xx,yy,x,y;
	char q,p;
	cin>>xx>>x>>q>>yy>>y>>p;
	if(xx==yy){
		cout<<'1';
		if(x==y){
			cout<<'1';
			if(q=='A'||q=='B'||q=='C'){
				if(p=='A'||p=='B'||p=='C'){
					cout<<'1';
					if(q=='B'||p=='B')cout<<'1';
					else cout<<'0';
				}
				else cout<<'0';
			}
			else if(p=='F'||p=='D')cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
