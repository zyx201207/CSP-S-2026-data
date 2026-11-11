#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1[100],s1[100],c2[100],s2[100],num[100];
	for(int i=1;i<=10;i++){
	    cin>>c1[i];
	    cin>>s1[i];
		cin>>c2[i];
		cin>>s2[i]; 
	}
	if(c1[0]==s1[0]&&c1[1]==s1[1]){
		num[0]='1';
		if(c2[0]==s2[0]&&c2[1]==c2[1]){
			num[1]='1';
			if(c2[2]==s2[2]){
				num[2]='1';
			}
		}
		else {
			num[0]='1';
			num[1]='0';
			num[2]='0';
			num[3]='0';
		}
	}
	else {
			num[0]='0';
			num[1]='0';
			num[2]='0';
			num[3]='0';
		}
	cout<<num;
}
