#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	string a,b,aa,bb;
	cin>>a>>b>>aa>>bb;
	set<char> ABC={'A','B','C'},DF={'D','F'};
	string s;
	s.push_back(b[2]),s.push_back(bb[2]);
	sort(s.begin(),s.end());
	set<string> xl={"AB","BC","DF"};
	cout<<(a==aa)<<((a==aa)&&(b.substr(0,2)==bb.substr(0,2)))<<((a==aa)&&(b.substr(0,2)==bb.substr(0,2))&&(ABC.count(b[2])==ABC.count(bb[2])&&DF.count(b[2])==DF.count(bb[2])))<<((a==aa)&&(b.substr(0,2)==bb.substr(0,2))&&(ABC.count(b[2])==ABC.count(bb[2])&&DF.count(b[2])==DF.count(bb[2]))&&xl.count(s));
	return 0;
}
