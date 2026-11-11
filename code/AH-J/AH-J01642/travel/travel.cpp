#include<bits/stdc++.h>
using namespace std;
int a[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,s2;
	string c1,c2;
	cin>>s1>>c1>>s2>>c2;
	if(s1%16!=1&&s2%16!=1&&s1==s2){
		a[1]=1;	
		if(c1[0]==c2[0]&&c1[1]==c2[1]){
			a[2]=1;
			if((c1[2]>='A'&&c1[2]<='C'&&c2[2]>='A'&&c2[2]<='C')||(c1[2]>='D'&&c1[2]<='F'&&c2[2]>='F'&&c2[2]<='D')){
				a[3]=1;	
				if(abs(c1[2]-c2[2])==1){
					a[4]=1;
				}
			}
		}
}
	for(int i=1;i<=4;i++) cout<<a[i];
	return 0;
}
