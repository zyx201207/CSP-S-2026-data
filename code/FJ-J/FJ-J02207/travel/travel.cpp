#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<string> s1[3],s2[3];
	int c1,c2,y1,y2;
	cin>>c1;
	for(int i=1;i<=3;i++) cin>>s1[i];
	cin>>c2;
	for(int i=1;i<=3;i++) cin>>s2[i];
	if(c1==c2) cout<<"1";
	else cout<<"0";
	if(s1.pop()==s2.pop()) cout<<"1";
	else cout<<"0";
}
