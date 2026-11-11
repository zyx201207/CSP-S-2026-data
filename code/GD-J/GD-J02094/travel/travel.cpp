#include<bits/stdc++.h>
using namespace std;
int a,b,n;
string a1,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>b>>b1;
	if(a==b){
		n+=1000;
		if(a1[0]==b1[0]&&a1[1]==b1[1]){
			n+=100;
			if((a1[2]==65||a1[2]==66||a1[2]==67)&&(b1[2]==65||b1[2]==66||b1[2]==67)){
				n+=10;
				if(abs(a1[2]-b1[2])==1)n++;
			}else if(((a1[2]==68||a1[2]==70)&&(b1[2]==68||b1[2]==70)))n+=11;
		}
	}
	if(n==0)cout<<"0000";
	else cout<<n;
	return 0;
}
