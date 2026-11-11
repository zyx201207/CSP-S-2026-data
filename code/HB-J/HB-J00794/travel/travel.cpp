#include<bits/stdc++.h>
using namespace std;
char c1[2],c2[2];
char s1[3],s2[3];
bool cmp1(char a[],char b[],int n){
	int flag=1;
	for(int i=0;i<n;i++){
		if(a[i]!=b[i])flag=0;
	}
	return flag;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	for(int i=0;i<=1;i++)cin>>c1[i];
	for(int i=0;i<=2;i++)cin>>s1[i];
	for(int i=0;i<=1;i++)cin>>c2[i];
	for(int i=0;i<=2;i++)cin>>s2[i];
	if(cmp1(c1,c2,2)){
		cout<<"1";
		if(cmp1(s1,s2,2)){
			cout<<"1";
			if((s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67)||((s1[2]==68||s1[2]==70)&&(s2[2]==68||s2[2]==70))){
				cout<<"1";
				if(s1[2]>=65&&s1[2]<=67&&s2[2]>=65&&s2[2]<=67&&abs(s1[2]-s2[2])==1)cout<<"1";
				else if((s1[2]==68||s1[2]==70)&&(s2[2]==68||s2[2]==70))cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
