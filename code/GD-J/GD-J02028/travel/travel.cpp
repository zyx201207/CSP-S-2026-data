#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	int f=1,s=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=s*10+ch-'0';ch=getchar();}
	return s*f;
} 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a[0]!=c[0]||a[1]!=c[1]){cout<<"0000";return 0;}
	if(b[0]!=d[0]||b[1]!=d[1]){cout<<"1000";return 0;}
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='D'||d[2]=='E')){cout<<"1100";return 0;}
	if((d[2]=='A'||d[2]=='B'||d[2]=='C')&&(b[2]=='D'||b[2]=='E')){cout<<"1100";return 0;}
	if(abs(b[2]-d[2])!=1){cout<<"1110";return 0;}
	cout<<"1111";
	return 0;
}
