#include<bits/stdc++.h>
using namespace std;
int n;
long long sum;
string s,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string c;
		cin>>x>>c;
		sum+=x;
		for(int j=1;j<=x;j++)s+=c;
	}
	long long l=s.size();
	for(int i=l-1;i>=0;i--){
		s2+=s[i];
	}
	if(s!=s2&&l%2==0){
		cout<<sum/2;
	}else{
		for(int i=0;i<l;i++){
			if(s2[i]==s[i]){
				cout<<i;
				return 0;
			}
		}
	}
	return 0;
}
/*
6
1000 a
1000 a
1000 a
1000 b
1000 b
1000 b
*/
