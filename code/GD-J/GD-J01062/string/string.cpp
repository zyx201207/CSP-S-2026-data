#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,sum=0;
	cin>>n;
	int m;
	string a,s;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>a;
		for(int j=1;j<=m;j++){
			s+=a;
		}
	}
	for(int i=0;i<s.size();i++){
		int p=s.size()-1;
		if(s[i]!=s[p]){
			sum++;
			s[p]=s[i];
		}
		p--;
	}
	cout<<sum;
	return 0;
}
