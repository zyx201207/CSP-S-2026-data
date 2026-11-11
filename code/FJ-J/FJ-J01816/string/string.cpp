#include<bits/stdc++.h>
using namespace std;
long long a[200050]={};
char b[200050]={};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;cin>>n;
	string s;
	long long num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		l+=a[i];
		for(int j=0;j<a[i];j++){
			s+=b[i];
		}
	}

	int x=s.size();
	for(int i=0;i<=x/2;i++){
		if(s[i]!=s[x-1-i]) num++;
	}
	cout<<num;
	
	return 0;
}
