//GZ-J00411 贵阳市南明区华麟学校 张喆品 
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[10]={'A','B','C','D','F'};
int cnt,idx;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)cout<<'1';
	else cout<<'0';
	int n=0,m=0;
	for(int i=0;i<=1;i++)n+=int(c2[i]);
	for(int i=0;i<=1;i++)m+=int(s2[i]);
	if(c1==s1&&n==m)cout<<'1';
	else cout<<'0';
	for(int i=0;i<5;i++){
		if(c2[2]==a[i])cnt=i+1;
		if(s2[2]==a[i])idx=i+1;
	}
	if(c1==s1&&n==m){
		if(cnt>=1&&cnt<=3&&idx>=1&&idx<=3){
			cout<<'1';
		}
		else if(cnt>3&&cnt<=5&&idx>3&&idx<=5){
			cout<<'1';
		}
		else cout<<'0';
	}
	else cout<<0;
	if(c1==s1&&n==m){
		if(cnt>=1&&cnt<=3&&idx>=1&&idx<=3&&abs(idx-cnt)==1){
			cout<<'1';
		}
		else if(cnt>3&&cnt<=5&&idx>3&&idx<=5&&abs(idx-cnt)==1){
			cout<<'1';
		}
		else cout<<'0';
	}	
	else cout<<'0';
	return 0;
}
