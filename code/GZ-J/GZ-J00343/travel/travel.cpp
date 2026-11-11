//GZ-J00343 ¹óÑôË«Áú»ª÷ëÑ§Ğ£ ÎâÅæÁØ 
#include<bits/stdc++.h>
using namespace std;
string s;
int a[5],b[5],c[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=2;i++){
		cin>>s;
		if(s[0]='0') a[i]=0;
		else a[i]=1;
		int h=s[1]-'0'+0;
		a[i]=a[i]*10+h;
		h=0;
		cin>>s;
		if(s[0]='0') b[i]=0;
		else b[i]=1;
		h=s[1]-'0'+0;
		b[i]=b[i]*10+h;
		if(s[2]=='A') c[i]=1;
		else if(s[2]=='B') c[i]=2;
		else if(s[2]=='C') c[i]=3;
		else if(s[2]=='D') c[i]=4;
		else c[i]=5;
	}
	if(a[1]!=a[2]) cout<<"0000";
	else{
		if(b[1]!=b[2]) cout<<"1000";
		else{
			if(c[1]<=3&&c[2]>=4) cout<<"1100";
			else if(c[1]>=4&&c[2]<=3) cout<<"1100";
			else{
				if(c[1]-c[2]==-1||c[1]-c[2]==1) cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
