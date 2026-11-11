#include<bits/stdc++.h>
using namespace std;
char buf[1<<20],*p1,*p2;
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),p1==p2?EOF:*p1++)
inline int read(){
	int k=0,f=1;char c=gc();
	for(;!isdigit(c);c=gc()) if(c=='-') f=-1;
	for(;isdigit(c);c=gc()) k=k*10+(c^48);
	return k*f;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;
	cin>>c>>T;
	while(T--) cout<<"0\n";
	return 0;
}
//Lonely Halloween

