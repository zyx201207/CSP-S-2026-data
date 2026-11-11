#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
struct Segment{
	int v=0;
	bool f=false;
	Segment(){}
	Segment(int _v,int _f):v(_v),f(_f){}
};
vector<Segment>s;
int a[N];
int n,d;
int T;
bool b=false;
inline int dis(const int&__x,const int&__y){return a[__y]-a[__x];}
inline bool ok(const int&__x,const int&__y){return (a[__y]-a[__x])<=d;}
int _c; 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>_c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		Segment temp;
		b=false;s.resize(0);
		for(int i=1;i<=n;i++){
			if(b)temp.f=true,b=false;
			temp.v++;
			if(i<=n-2){
				if(ok(i,i+2)&&ok(i,i+1)){	
					s.push_back(temp);
					temp.v=0;
				}
			}
			if(i<=n-1){
				if(!ok(i,i+1)){
					b=true;
					s.push_back(temp);
					temp.v=0;
				}
			}
		}
		int ans=0;
		for(int i=1;i<(int)s.size();i++){
			if(s[i].f)continue;
			ans+=s[i].v*s[i-1].v;
		}
		cout<<ans<<"\n";
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
