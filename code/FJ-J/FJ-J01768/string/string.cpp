#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	vector<char> s;
	vector<char> str;
	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		char c;
		cin>>c;
		while(num--){
			s.push_back(c);
		}
	}
	int l=s.size()/2;
	reverse(s.end()-l+1,s.end());
	for(int i=s.size()-l;i<s.size();i++){
		str.push_back(s[i]);
	}
	for(int i=0;i<l;i++){
		if(s[i]!=str[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
