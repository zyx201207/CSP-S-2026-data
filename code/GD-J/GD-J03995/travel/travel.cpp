#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[5];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[1]=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a[2]=1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				a[3]=1;
				if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
					a[4]=1;
				}
			}
		}
	}
	for(int i=1;i<=4;i++){
		cout<<a[i];
	}
	cout<<'\n';
	return 0;
} 
