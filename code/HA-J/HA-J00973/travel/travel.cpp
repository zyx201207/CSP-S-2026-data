#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
int a[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<4;i++){
		if(i==0){
			if(c1==c2)a[0]=1;
			else {
				a[0]=0;break;
			}
		}else if(i==1){
			if((s1[1]==s2[1])&&(s1[0]==s2[0])&&(a[0]==1))a[1]=1;
			else {
				a[1]=0;break;
			}
		}else if(i==2){
			if(((s1[2]<='C')&&(s2[2]<='C'))||((s1[2]>'C')&&(s2[2]>'C'))&&(a[1]==1))a[2]=1;
			else {
				a[2]=0;	break;
			}
		}else if(i==3){
			if(((int(s1[2]-s2[2])==1)||(int(s2[2]-s1[2])==1)||((s1[2]=='D')&&(s2[2]=='F')))&&(a[2]==1))a[3]=1;
			else {
				a[3]=0;
			}
		}
	}
	cout<<a[0]<<a[1]<<a[2]<<a[3];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

