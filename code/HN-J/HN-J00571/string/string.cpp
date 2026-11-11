#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
long long n,a1,some;
char c1;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1>>c1;
		for(int j=1;j<=a1;j++){
			s+=c1;
		}
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	int l=0,r=s.size()-1;
	while(l<=r){
		l++,r--;
		if(s[l]!=s[r]){
			some++;	
		}
	}
	cout<<some;
	return 0;
}
