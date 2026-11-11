#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[4];
int main(){
	a[0]=0;a[1]=0;a[2]=0;a[3]=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[1]=1;
			if((s1[2]-'A'<3&&s2[2]-'A'<3)){
				a[2]=1;
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					a[3]=1;
				}
			}
			if(((s1[2]-'D')==0||(s1[2]-'D')==2)&&((s2[2]-'D')==0||(s2[2]-'D')==2)){
				if(s1[2]-s2[2]==2||s1[2]-s2[2]==-2){
					a[3]=1;
				}
				a[2]=1;
			}
		}
	} 
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
