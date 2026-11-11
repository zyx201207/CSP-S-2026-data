#include<bits/stdc++.h>
using namespace std;
int n;
long long sum = 0,ans;
bool check(string a){
	string s = a;
	reverse(s.begin(),s.end());
	return s == a;
}
string s;
int maxx = 0;
int main(){
	freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	cin>>n;
	for(int i = 0; i < n; i ++){
		int val;
		char a;
		cin>>val>>a;
		maxx = max(maxx,val);
		for(int j = 0;j < val; j ++){
			s+=a;
		}
	}
	if(check(s)){
		cout<<"0";
	}else{
		cout<<maxx;
	}
	return 0;
}

