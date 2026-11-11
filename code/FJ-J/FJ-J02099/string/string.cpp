#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n,x;
	char a;
	long long t=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a;
		for(int j=1;j<=x;j++){
			s+=a;
		}
	}
	int m=s.size();int l=s.size()-1;
	if(m%2!=0)
		m=(m-1)/2;
	else
		m=m/2;
	for(int i=0;i<=m-1;i++){
			if(s[i]!=s[l-i])
				t++;
		}
	cout<<t;
	return 0;
}
