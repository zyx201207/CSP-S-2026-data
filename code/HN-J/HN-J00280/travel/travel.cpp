#include<bits/stdc++.h>
using namespace std;
int c1, c2;
string s1, s2;
int main(){
	ios::sync_with_stdio();
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0] == s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if((s1[2]<='c')==(s2[2]<='c')){
				cout<<1;
				cout<<(abs(s1[2]-s2[2])==1)<<'\n';
			}
		}
	}
	//cout<<(c1==c2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
