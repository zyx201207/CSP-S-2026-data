#include<bits/stdc++.h>
using namespace std;
bool p[4]={0};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string a1,b1;
	cin>>a>>a1>>b>>b1;
	if(a[0]==b[0] && a[1]==b[1]){
		p[0]=1;
		if(a1[0]==b1[0] && a1[1]==b1[1]){
			p[1]=1;
			if((a1[2]=='A' || a1[2]=='B' || a1[2]=='C') && (b1[2]=='A' || b1[2]=='B' || b1[2]=='C')){
				p[2]=1;
				if(a1[2]+1==b1[2] || a1[2]-1==b1[2]){
					p[3]=1;
				}
			}else if((a1[2]=='D' || a1[2]=='F' ) && (a1[2]=='D' || a1[2]=='F')){
				p[2]=1;
				p[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++){
		cout<<p[i];
	}
	
	return 0;
}
