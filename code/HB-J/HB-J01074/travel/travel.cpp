#include <bits/stdc++.h>
using namespace std;
#define int long long
int c1 = 02,c2 = 02;
int ans1,ans2,ans3,ans4;
string s1 = 01A,s2 = 01B; 
signed main (){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("travel.in","w",stdin);
	freopen("travel.out","r",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		ans1 = 0;
	}
	else{
		ans1 = 1;
	}
	if(s1[0] == s2[0] and s1[1] == s2[1]){
		ans2 = 1;
	}
	else{
		ans2 = 0;
	}
	if(ans2 == 1){
		if(s2 == 'A' or s2 == 'B' or s2 == 'C' and s1 == 'A' or s1 == 'B' or s1 == 'C'){
			ans3 = 1;
		}
		else if(s2 == 'D' or s2 == 'F' and s1 == 'D' or s1 == 'F'){
			ans3 = 1;
		}
		else ans3 = 0;
 	}
 	if(s1[3] == s2[3]+1 or s1[3] == s2[3]-1 and s1[3]+1 != 'D' or s2[3]+1 != 'D'){
		ans4 = 1;
	}
	else {
		ans4 != 0;
	}
	
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
