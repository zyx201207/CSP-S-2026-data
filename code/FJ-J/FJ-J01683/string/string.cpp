#include <bits/stdc++.h>
using namespace std;


int main(){
	freopen("string.in","r",stdin);
	frepoen("string.out","w",stdout);
	string s;
	longlong n,a,sum=0,sl;
	char c;
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
		
			s.push_back(c);
		}
	}
	
	sl=s.size();
	for(int i=0;2*(i+1)<=sl;i++){
		if(s[i]!=s[sl-1-i]){
			
			sum++;
		}
	}
	cout<<sum;
	
	
	
	return 0;

}
