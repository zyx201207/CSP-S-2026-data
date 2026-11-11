#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
	cin>>a1>>a2>>b1>>b2;
	cout<<(a1==b1?1:0)<<(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]?1:0)<<(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'||a2[2]>='D'&&a2[2]<'F'&&b2[2]>='D'&&b2[2]<='F')?1:0)<<(a1==b1&&a2[0]==b2[0]&&a2[1]==b2[1]&&(a2[2]>='A'&&a2[2]<='C'&&b2[2]>='A'&&b2[2]<='C'||a2[2]>='D'&&a2[2]<'F'&&b2[2]>='D'&&b2[2]<='F')&&abs(a2[2]-b2[2])==1?1:0);
	return 0;
}
