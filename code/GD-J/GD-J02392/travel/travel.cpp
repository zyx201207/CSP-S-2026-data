#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[20],s2[20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			bool same_side=1,l;
			if(s1[2]<='C'){
				l=1;
			}else{
				l=0;
			}
			if(l == (s2[2]<='C')){
				if(abs(s1[2]-s2[2])==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
			
		}else{
			cout<<"1000";
		}
	}
}
