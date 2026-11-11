#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	
	string a="0000";
	if(c1[0]==c2[0]&&c1[1]==c2[1])a[0]++;
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a[1]++;
		if(s1[2]<='C'&&s2[2]<='C')a[2]++;
		if(s1[2]>='D'&&s2[2]>='D')a[2]++;
		if(a[2]=='1'){
			if(s1[2]+1==s2[2]||s1[2]-1==s2[2])a[3]++;
			else if(s1[2]=='D'&&s2[2]=='F')a[3]++;
			else if(s1[2]=='F'&&s2[2]=='D')a[3]++;
		}
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
