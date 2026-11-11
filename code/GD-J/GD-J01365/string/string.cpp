#include<bits/stdc++.h>
using namespace std;
const int N=1e9*2+5;
int main(){
//	freopen("string.in","r",stdin);
//	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	string s;
	int a;
	char c;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	cout<<s;
}
