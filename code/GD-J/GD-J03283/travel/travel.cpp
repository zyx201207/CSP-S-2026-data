#include<bits/stdc++.h>
using namespace std;
map<char,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string nu1,pr1,nu2,pr2;
	cin>>nu1>>pr1>>nu2>>pr2;
	mp['A'] = mp['B'] = mp['C'] = 1;
	mp['D'] = mp['F'] = 2;
	if(nu1!=nu2) cout<<"0000";
	else{
		cout<<'1';
		if(pr1.substr(0,2)==pr2.substr(0,2)){
			cout<<'1';
			if(mp[pr1[2]]==mp[pr2[2]]){
				cout<<'1';
				if(abs(int(pr1[2]-pr2[2]))==1) cout<<'1';
				else cout<<'0';
			} 
			else cout<<'00';
		}
		else cout<<'000';		
	}
	return 0;
} 
