#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,x1,x2;
	cin>>r1>>r2>>x1>>x2;
	int a[4]={};
	if(r1==x1){
		a[0]=1;
		string s1,s2;
		s1=r2[0]+r2[1];
		s2=x2[0]+x2[1];
		if(s1==s2){
			a[1]=1;
			if(r2[2]>='A'&&r2[2]<='C'&&x2[2]>='A'&&x2[2]<='C'){
				a[2]=1;
				int m=r2[2],n=x2[2];
				if(abs(m-n)==1) a[3]=1;
			}
			if(r2[2]>='D'&&r2[2]<='F'&&x2[2]>='D'&&x2[2]<='F'){
				a[2]=1;a[3]=1;
			}
		}
	}
	for(int i=0;i<4;i++) cout<<a[i];
	fclose(stdin);
	fclose(stdout);
	return 0;
}
