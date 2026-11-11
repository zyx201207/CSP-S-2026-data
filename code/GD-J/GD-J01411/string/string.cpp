#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,an[N],ac[N],anf=1,x;
string s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		int x1,x2;
		char c;
		cin>>x1>>c>>x2>>c;
		cout<<min(x1,x2);
	}
	cin>>x;
	cout<<x*n/2;
	return 0;
}
