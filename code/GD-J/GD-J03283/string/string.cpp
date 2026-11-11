#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int n;
	cin>>n;
	string a;
	for(int i = 1;i <= n;i++){
		int x;
		cin>>x;
		char c;
		cin>>c;
		for(int i = 0;i < x;i++){
			a += c;
		}
	} 
	long long l = 0,r = a.length()-1;
	long long cn = 0;
	while(l<=r){
		if(a[l]!=a[r]){
			cn++;
		}
		l++,r--;
	}
	cout<<cn;
	return 0;
}
