#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	int a[6]= { };
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		a[1]=1;
		if(s1[1]==s2[1]&&s1[0]==s2[0]) {
			a[2]=1;
			if(s1[2]==65||s1[2]==66||s1[2]==67) {
				if(s2[2]==65||s2[2]==66||s2[2]==67) {
					a[3]=1;
					if(s1[2]==65&&s2[2]==66) {
						a[4]=1;
					}
					if(s1[2]==66&&(s2[2]==65||s2[2]==67)) {
						a[4]=1;
					}
				}
			} else if(s2[2]==68||s2[2]==70) {
				a[3]=1;
				if((s1[2]==68&&s2[2]==70)||(s1[2]==70&&s2[2]==68)) {
					a[4]=1;
				}
			}
		}
	}
      for(int i=1;i<=4;i++){
      	cout<<a[i];
      	
	  }
   return 0;
}



