#include<bits/stdc++.h>
using namespace std;
int cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int ans=0;
	string s;
	for(int i=1;i<=n;i++){
		int nn;
		char a;
		cin>>nn;
		cin>>a;
		ans+=nn;
		for(int i=1;i<=nn;i++){
			s+=a;
		}
	}
		int p=ans/2;
	int k=ans-1;
	for(int i=0;i<p;i++){
		if(s[k-i]!=s[i]){
			cnt++;
		}
	}
	cout<<cnt;

	return 0;
	
}