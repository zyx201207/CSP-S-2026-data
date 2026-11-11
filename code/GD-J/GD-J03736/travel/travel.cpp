#include<bits/stdc++.h>
#define int long long
#define endl '/n'
using namespace std;
signed main(){
	//freopen(travel.in,"r",stdin);
	//freopen(travel.out,"w",stdout);
	cin.tie(NULL);
	cout.tie(NULL);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans = 0;
	if(c1 == c2){
		cout<<1;
		ans += 1;
	}
	else{
		cout<<0;
	}
	
	if(ans == 1 && s1[1] == s2[1]){
		cout<<1;
		ans += 1;
	}
	else{
		cout<<0;
	}
	
	if(ans == 2 && (s1[2] < 'D' && s2[2] < 'D' || s1[2] > 'C' && s2[2] > 'C')){
		cout<<1;
		ans += 1;
	}
	else{
		cout<<0;
	}
	
	if(ans == 3){
		if(s1[2] == 'A' && s2[2] == 'B' || s1[2] == 'B' && s2[2] == 'A'){
			cout<<1;
		}
		else if(s1[2] == 'B' && s2[2] == 'C' || s1[2] == 'C' && s2[2] == 'B'){
			cout<<1;
		}
		else if(s1[2] == 'D' && s2[2] == 'E' || s1[2] == 'E' && s2[2] == 'D'){
			cout<<1;
		}
		else{
			cout<<0;
		}
	}
	else{
		cout<<0;
	}
	return 0;
} 
