#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	vector<char> s;
	for(ll i = 0;i<n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(ll j = 0;j<a;j++){
			s.push_back(c);
		}
	}
	stack<char> a;
	int cnt = 0;
	if(s.size() % 2 == 0){
		for(ll i = 0;i<s.size()/2;i++){
			a.push(s[i]);
		}
		for(ll i = s.size()-1;i>=s.size()/2;i--){
			if(s[i] != a.top()){
				a.pop();
				cnt++;
			}
		}
		cout<<cnt;
	}else if(s.size() % 2 == 1){
		for(ll i = 0;i<floor(s.size()*1.0/2);i++){
			a.push(s[i]);
		}
		for(ll i = s.size()-1;i>=(ceil(s.size()*1.0/2));i--){
			if(s[i] != a.top()){
				a.pop();
				cnt++;
			}
		}
		cout<<cnt;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
