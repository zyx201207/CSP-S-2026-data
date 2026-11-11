#include<bits/stdc++.h>
using namespace std;

int n,ans;
string a;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int tmp1;
		char tmp2;
		cin>>tmp1>>tmp2;
		while(tmp1--){
			a+=tmp2;
		}
	}
	for(int l=0,r=a.length()-1;l<r;l++,r--){
		if(a[l]!=a[r]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
