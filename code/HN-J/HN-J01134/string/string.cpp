#include<bits/stdc++.h>
using namespace std;
vector<char> a; 
int n,ans=0;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++) a.push_back(y);
	}
	int len=a.size();
	int tp=len;
	for(int i=1;i<=len/2;i++){
		if(a[0]!=a[tp-1])
		ans++;
			a.erase(a.begin());
			a.pop_back();
		tp-=2;
	}
	cout<<ans; 
	return 0; 
}
