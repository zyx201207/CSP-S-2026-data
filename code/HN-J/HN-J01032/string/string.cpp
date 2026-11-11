#include <bits/stdc++.h>
using namespace std;
vector<char>v;
int res;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	int n;
	cin>>n; 
	for(int i = 0; i < n; i++){
		int nu; char c;
		scanf("%d %c",&nu, &c);
		for(int j = 1; j <= nu; j++)
			v.push_back(c) ;
	}	
	for(int i = 0; i <= v.size()/2; i++){
		if(v[i] != v[n-i]){
			res++;
		}
	}
	cout<<res;
	return 0;
}
