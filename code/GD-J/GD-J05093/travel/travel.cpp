#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[2]=1;
			if((s1[2]=='A'&&(s2[2]=='B'||s2[2]=='C'))||(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C'))||(s1[2]=='C'&&(s2[2]=='A'||s2[2]=='B'))||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				a[3]=1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					a[4]=1;
				}
			}
		}
	}
	cout<<a[1]<<a[2]<<a[3]<<a[4]<<'\n';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
