#include<bits/stdc++.h>
using namespace std;

bool f(string s_1,string s_2){
	
	int n=s_1.size();
	
	if(n-s_2.size()) return false;
	
	for(int i=0;i<n-1;i++) if(s_1[i]-s_2[i]) return false;
	
	
	return true;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	bool b=true;
	string c_1,s_1,c_2,s_2;
	
	cin >> c_1 >> s_1 >> c_2 >> s_2;
	int n=s_1.size();
	
	b=b&&c_1==c_2;
	cout << b;
	b=b&&f(s_1,s_2);
	cout << b;
	b=b&&(s_1[n-1]<'D'&&s_2[n-1]<'D')||(s_1[n-1]>'C'&&s_2[n-1]>'C');
	cout << b;
	b=b&&abs(s_1[n-1]-s_2[n-1])<2;
	cout << b;
	
	return 0;
}
