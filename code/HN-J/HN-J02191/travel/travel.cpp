#include<bits/stdc++.h> 
using namespace std;
int a,b;
string s,ss,sa="ABC",sb="DF";
bool c,p,yc,l;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>ss;
	if(a==b){
		c=1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			p=1;
			if(s[2]==sa[0]||s[2]==sa[1]||s[2]==sa[2]){
				for(int i=0;i<=2;i++){
					if(ss[2]==sa[i]){
						yc=1;
						if(char(s[2]+1)==ss[2]||char(s[2]-1)==ss[2]){
							l=1;
						}
						break;
					}
				}
			}
			if(s[2]==sb[0]||s[2]==sb[1]){
				for(int i=0;i<=1;i++){
					if(ss[2]==sb[i]){
						yc=1;
						if(char(s[2]+1)==ss[2]||char(s[2]-1)==ss[2]){
							l=1;
						}
						break;
					}
				}
			}
			
		}
	}
	cout<<c<<p<<yc<<l;
	return 0;
}
