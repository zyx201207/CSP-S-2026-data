#include <bits/stdc++.h>
using namespace std;
int n;
string s="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		string c;
		int a;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}int r=0,l=s.size()-1,x;
	while(r<l){
		if(s[r]!=s[l]){
			x++;
		}r++;
		l--;
	}cout<<x;
	
	return 0;
}
