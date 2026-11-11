#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ll long long
using namespace std;

const int N=15;

//char c1[N],s1[N],c2[N],s2[N];
string c1,s1,c2,s2;

#define chk(c,A,B) ((A<=c)&&(c<=B))

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fast;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((chk(s1[2],'A','C')&&chk(s2[2],'A','C'))||
			   (chk(s1[2],'D','E')&&chk(s2[2],'D','E'))){
				cout<<1;
				if(abs(s1[2]-s2[2])==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
