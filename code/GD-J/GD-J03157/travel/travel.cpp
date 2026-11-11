#include<bits/stdc++.h>
#define ll long long
#define ri register int
#define stg string
#define Cn const
#define ld long double
using namespace std;
int read() {
    int r=0,fl=1;char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') fl=-fl;c=getchar();}
    while(c>='0'&&c<='9') {r=(r<<3)+(r<<1)+(c^48);c=getchar();}
    return r*fl;
}
int Max(int a,int b) {return a>b?a:b;}
int Min(int a,int b) {return a<b?a:b;}
Cn ld eps=1e-9;
Cn ll Inf=1e18;
Cn int typ[6]={1,1,1,2,-1,2};
Cn int wz[6]={1,2,3,5,-1,6};
stg s1,s2,s3,s4;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) {
		cout<<"1";
		if(s2[0]==s4[0]&&s2[1]==s4[1]) {
			cout<<"1";
			int a=s2[2]-'A',b=s4[2]-'A';//cout<<a<<" "<<b<<endl;
			if(typ[a]==typ[b]) {
				cout<<"1";
				if(abs(wz[a]-wz[b])==1) {
					cout<<"1";
				} else cout<<"0";
			} else cout<<"00";
		} else cout<<"000";
	} else cout<<"0000";
	return 0;
}
