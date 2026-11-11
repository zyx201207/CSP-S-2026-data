#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		int w=(s1[0]-'0')*10+(s1[1]-'0');
		int q=(s2[0]-'0')*10+(s2[1]-'0');
		if(w==q){
			if(s1[2]>='D'){
				if(s2[2]>='D'){
					if(s1[2]>s2[2]){
						if(s1[2]-'A'+1==s1[2]-'A') cout<<1111;
						else cout<<1110; 
					}
				}else cout<<1100;
			}else if(s1[2]<='C'){
				if(s2[2]<='C'){
					if(s1[2]>s2[2]){
						int a=s2[2]-'A'+1;
						int b=s1[2]-'A';
						if(a==b) cout<<1111;
						else cout<<1110; 
					}else{
						int a=s1[2]-'A'+1;
						int b=s2[2]-'A';
						if(a==b) cout<<1111;
						else cout<<1110; 
					}
				}else cout<<1100;
			}
		}else cout<<1000;
	}else cout<<"0000";
	return 0;
}
