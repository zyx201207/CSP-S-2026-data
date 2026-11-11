#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
string c1,s1,c2,s2;
int k=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		k++;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			k++;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				k++;
				if((s1[2]>='D'&&s2[2]>='D'&&abs(int(s1[2]-s2[2]))==2)||(s1[2]<='C'&&s2[2]<='C'&&abs(int(s1[2]-s2[2]))==1)) k++;	
			}
		}
	}
	if(k==0) cout<<k<<k<<k<<k;
	if(k==1) cout<<1000;
	if(k==2) cout<<1100;
	if(k==3) cout<<1110;
	if(k==4) cout<<1111;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

