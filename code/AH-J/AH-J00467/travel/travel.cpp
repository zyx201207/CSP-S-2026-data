#include<bits/stdc++.h>
using namespace std;
char s1[4],s2[4],c1[3],c2[3];
int n,m,k,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2]>>s1[1]>>s1[2]>>s1[3]>>c2[1]>>c2[2]>>s2[1]>>s2[2]>>s2[3];
	if (c1[1]==c2[1]&&c1[2]==c2[2]) n=1;
	if (s1[1]==s2[1]&&s1[2]==s2[2]&&n==1) m=1;
	if ((s1[3]=='D'||s1[3]=='F')&&(s2[3]=='D'||s2[3]=='F')&&m==1) {
		k=1;l=1;
		cout<<n<<m<<k<<l;
		return 0;
	}
	else if (((s1[3]=='C'&&s2[3]=='D')||(s1[3]=='D'&&s2[3]=='C'))&&m==1) k=0;
	else if(m==1) k=1;
	if ((s1[3]+1==s2[3]||s2[3]+1==s1[3])&&k==1) l=1;
	
	cout<<n<<m<<k<<l;
	return 0;
} 
