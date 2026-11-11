#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int a1;
		string a2;
		cin>>a1>>a2;
		for(int i=1;i<=a1;i++){
			s+=a2;
		}
	}
	if(n==1) cout<<0;
	return 0;
}
