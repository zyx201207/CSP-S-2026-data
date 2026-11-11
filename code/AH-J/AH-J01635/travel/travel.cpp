#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[10];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a[0]=1;
	}
	if(s1[0]==s2[0]&&s2[1]==s1[1]&&a[0]==1){
		a[1]=1;
	}
	for(int i=0;i<=2;i++){
		if(s1[i]=='A'){s1[i]='1';}
		if(s1[i]=='B'){s1[i]='2';}
		if(s1[i]=='C'){s1[i]='3';}
		if(s1[i]=='D'){s1[i]='4';}
		if(s1[i]=='F'){s1[i]='5';}
		if(s2[i]=='A'){s2[i]='1';}
		if(s2[i]=='B'){s2[i]='2';}
		if(s2[i]=='C'){s2[i]='3';}
		if(s2[i]=='D'){s2[i]='4';}
		if(s2[i]=='F'){s2[i]='5';}
	}
//    cout<<s1<<s2;
	if(a[1]==1){
		if(s1[2]=='1'||s1[2]=='2'||s1[2]=='3'){
			if(s2[2]=='1'||s2[2]=='2'||s2[2]=='3'){
				a[2]=1;
				if(s1[2]-'0'>s2[2]-'0'&&s1[2]-s2[2]==1){
					a[3]=1;
				}
				if(s1[2]-'0'<s2[2]-'0'&&s2[2]-s1[2]==1){
					a[3]=1;
				}
			}
		}else if(s1[2]=='4'||s1[2]=='5'){
			if(s2[2]=='4'||s2[2]=='5'){
				a[2]=1;
				if(s1[2]-'0'>s2[2]-'0'&&s1[2]-s2[2]==1){
					a[3]=1;
				}
				if(s1[2]-'0'<s2[2]-'0'&&s2[2]-s1[2]==1){
					a[3]=1;
				}
			}
		}
	}
	for(int i=0;i<=3;i++){
		cout<<a[i];
	}
	return 0;
}
