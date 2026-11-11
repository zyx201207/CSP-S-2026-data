//GZ-J00589 遵义市第四初级中学 蒋子涵 
#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char a,b,c,d,e,f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>a>>b>>c>>s2>>d>>e>>f;
	if(s1==s2){
		int x=int(a-'0')+int(b-'0');
		int y=int(d-'0')+int(e-'0');
		if(x==y){
			if((c<='C'&&f<='C')||(c>='D'&&f>='D')){
				if(abs(int(c-f))==1) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
