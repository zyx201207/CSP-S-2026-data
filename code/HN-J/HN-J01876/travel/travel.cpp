#include<bits/stdc++.h>
using namespace std;
#define int long long
#define IN(x) freopen(x".in","r",stdin),freopen(x".out","w",stdout)

struct zp{
	int x;
	char ch;
}s1,s2;

string c1,c2;
bool f[5];
signed main(){
	IN("travel");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1.x>>s1.ch>>c2>>s2.x>>s2.ch;
	if(c1==c2){
		f[1]=1;
		if(s1.x==s2.x){
			f[2]=1;
			int left=0;
			int right=0;
			if(s1.ch=='A'||s1.ch=='B'||s1.ch=='C'){
				left++;
			}
			else {
				right++;
			}
			if(s2.ch=='A'||s2.ch=='B'||s2.ch=='C'){
				left++;
			}
			else {
				right++;
			}
			
			
			if(left==2||right==2){
				f[3]=1;
				if(abs(s1.ch-s2.ch)==1){
					f[4]=1;
				}
			}
			
		}
	}
	
	for(int i=1;i<=4;i++){
		cout<<f[i];
	}
	
	return 0;
	
}
