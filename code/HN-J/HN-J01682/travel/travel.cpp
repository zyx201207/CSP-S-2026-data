#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string cr,sr,cx,sx;
bool a[11];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cr>>sr>>cx>>sx;
	if(cr[0]==cx[0]&&cr[1]==cx[1]){
		a[0]=1;
		if(sr[0]==sx[0]&&sr[1]==sx[1]){
			a[1]=1;
			if(((sr[2]=='A'||sr[2]=='B'||sr[2]=='C')&&(sx[2]=='A'||sx[2]=='B'||sx[2]=='C')&&sr[2]!=sx[2])||((sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D'))){
				a[2]=1;
				if((sr[2]=='A'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='A')||(sr[2]=='C'&&sx[2]=='B')||(sr[2]=='B'&&sx[2]=='C')||(sr[2]=='D'&&sx[2]=='F')||(sr[2]=='F'&&sx[2]=='D')){
					a[3]=1;
				}else{
					a[3]=0;
				}
			}else{
				a[2]=0;
				a[3]=0;
			}
		}else{
			a[1]=0;
			a[2]=0;
			a[3]=0;
		}
	}else{
		a[0]=0;
		a[1]=0;
		a[2]=0;
		a[3]=0;
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
