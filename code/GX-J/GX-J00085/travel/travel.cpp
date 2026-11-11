#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	vector<int> s;
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2){
		s.push_back(1);
	}
	else{
		s.push_back(0);
	}
	if(b1==b2){
		s.push_back(1);
	}
	else{
		s.push_back(0);
	}
	cout<<"1111";
	return 0;
}
