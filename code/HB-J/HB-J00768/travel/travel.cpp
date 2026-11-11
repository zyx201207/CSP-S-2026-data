#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[5]={0,0,0,0};
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]=1;
			int x,y;
			switch(s1[2]){
				case 'D':
				x=5;
				break;
				case 'F':
				x=6;
				break;
				case 'A':case 'B':case 'C':
				x=s1[2]-'A'+1;
				break;
			}
			switch(s2[2]){
				case 'D':
				y=5;
				break;
				case 'F':
				y=6;
				break;
				case 'A':case 'B':case 'C':
				y=s2[2]-'A'+1;
				break;
			}
			if((x<4&&y<4)||(x>4&&y>4)){
				a[2]=1;
				if(abs(x-y)==1){
					a[3]=1;
				}
			}
		}
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	return 0;
}
