#include <bits/stdc++.h>
using namespace std;
long long l,sum,dum;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>l;
	while(l--){
		int c;
		char w;
		cin>>c>>w;
		for(int i=1;i<=c;i++){
			s+=w;
		}
	}
	//cout<<s;
	for(int i=0;i<s.size()/2;i++){
		if(s[i]!=s[s.size()-i]){
			sum++;
			//cout<<sum<<" "<<i<<endl;
		}
	}
	for(int i=s.size();i>s.size()/2;i--){
		if(s[i]!=s[s.size()-i]){
			dum++;
			//cout<<dum<<" "<<i<<endl;
		}
	}
	cout<<min(sum,dum);
	return 0;
}
