#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	int t;
	cin>>t;
	string a="";
	while(t--){
		int s1;
		char a1;
		cin>>s1>>a1;
		while(s1--){
			a+=a1;
		}
	}
	string b=a;
	reverse(a.begin(),a.end());
	int sum=0;
	for(int i=0;i<a.length()/2;i++){
		if(a[i]!=b[i])sum++;
	}
	cout<<sum;
	return 0;
}
