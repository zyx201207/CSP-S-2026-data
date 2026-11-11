#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,lon=0;
	cin>>n;
	string s;
	for(int i=1;i<=n;i++){
		int x;
		string y;
		cin>>x>>y;
		lon+=x;
		for(int j=1;j<=x;j++){
			s+=y;
		}
	}
	int cnt=0;
	for(int i=0;i<lon/2;i++){
		if(s[i]!=s[lon-1-i]){
			cnt++;
		}
	} 
	cout<<cnt;
	return 0;
} 
