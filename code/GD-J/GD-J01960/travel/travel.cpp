#include<bits/stdc++.h>
using namespace std;
#define int long long
string c,s,cc,ss;
bool ans[9];
int id(char x){
	if(x == 'A'||x == 'B'||x == 'C') return 1;
	return 2;
}
bool check(char x,char y){
	if(x == 'A'){
		if(y == 'B') return 1;
		else return 0;
	}else if(x == 'B'){
		if(y == 'A'||y == 'C') return 1;
		else return 0;
	}else if(x == 'C'){
		if(y == 'B') return 1;
		else return 0;
	}else if(x == 'D'){
		if(y == 'F') return 1;
		else return 0;
	}else{
		if(y == 'D') return 1;
		else return 0;
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c == cc){
		ans[0] = 1;
		if(s[0] == ss[0]&&s[1] == ss[1]){
			ans[1] = 1;
			if(id(s[2]) == id(ss[2])){
				ans[2] = 1;
				if(check(s[2],ss[2])){
					ans[3] = 1;
				}
			}
		}
	}
	for(int i = 0;i<4;++i) cout<<ans[i];
} 
