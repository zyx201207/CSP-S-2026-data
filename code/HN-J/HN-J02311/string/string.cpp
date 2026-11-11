#include <bits/stdc++.h> 
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string s="";
	int n,a,sum=0;
	char c;
	
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a;
		cin >> c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-1-i]){
			sum++;
		}
	}
	cout << sum;
	return 0;
}
