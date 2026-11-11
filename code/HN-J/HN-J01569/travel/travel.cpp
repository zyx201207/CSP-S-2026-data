#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string x,y,z,k;
int s0[10],s1[10],c0[10],c1[10];
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>y>>z>>k;
	for(int i=0;i<2;i++){
		c0[i]=x[i]-'0';
		c1[i]=z[i]-'0';
	}
	for(int i=0;i<2;i++){
		s0[i]=y[i]-'0';
		s1[i]=k[i]-'0';
	}
	s0[2]=y[2]-'A'+1;
	s1[2]=k[2]-'A'+1;
	if(c0[0]==c1[0] && c0[1]==c1[1]){
		ans=ans+"1";
		if(s0[0]==s1[0] && s0[1]==s1[1]){
			ans=ans+"1";
			int a=s0[2],b=s1[2];
			if(a>b) swap(a,b);
			if((a>=1 && a<=3 && b>=1 && b<=3) || (a==4 && b==6)){
				ans=ans+"1";
				if(a==1 && b==2 || a==2 && b==3 || a==4 && b==6){
					ans=ans+"1";
				}else{
					ans=ans+"0";
				}
			}else{
				ans=ans+"00";
			}
		}else{
			ans=ans+"000";
		}
	}else{
		ans=ans+"0000";
	}
	cout<<ans<<'\n';
	return 0;
}
