#include<bits/stdc++.h>
using namespace std;

int main() {
	set<int>a;
	for(int i=0;i<5;i++){
		int t;
		cin>>t;
		a.push_back(t);
	}for(int i=0;i<a.size();i++){
		cout<<a[i];
	}
}
