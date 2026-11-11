#include<bits/stdc++.h>
using namespace std;
char c1[3],c2[3],s1[4],s2[4],strl[100];
int t1,t2;
char a1[5],a[100];
int main(){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	a1[0]='0';
	a1[1]='0';
	a1[2]='0';
	a1[3]='0';
	cin>>c1;
	cout<<"";
	cin>>s1;
	cout<<"";
	cin>>c2;
	cout<<"";
	cin>>s2;
	cout<<"";
	 

	if (1==1){
		a1[0]='1';
		if (s1[0]==s2[0]&&s1[1]==s2[1]){
			a1[1]='1';
			if ((s1[2]-'A'<=2&&s2[2]-'A'<=2)||(s1[2]-'A'>2&&s2[2]-'A'>2)){
				a1[2]='1';
				if ((s1[2]-s2[2]==1)||(s1[2]-s2[2]==1)||(s1[2]=='D'&&s2[2]=='F')||(s2[2]=='D'&&s1[2]=='F')){
					a1[3]='1';
				}
			}
		}
	}

	cout<<a1[0]<<a1[1]<<a1[2]<<a1[3];
	return 0;
}
