//GZ-J00620 ¹ùå°Ðù 
#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s="";
	for(int i=1;i<=n;i++){
		long long m;
		char sx;
		cin>>m>>sx;
		while(m--) s+=sx;
	}
	long long L=s.size()-1;
	long long c=0;
	for(int i=0;i<=L-i;i++){
		int lyl=s[i]-'a'+1;
		int yly=s[L-i]-'a'+1;
		if(lyl!=yly) c++;
	}
	cout<<c;
	return 0;
}
