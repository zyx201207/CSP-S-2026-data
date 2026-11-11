#include<bits/stdc++.h>
using namespace std;
int n;
long long l;
long long cnt;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		char c;
		cin>>c;
		for(int j=1;j<=a;j++){
			s+=c;
		}
	}
	l=s.size();
	for(int i=0,j=l-1;i<l/2+l%2;i++,j--){
		if((s[i]!=s[j])&&(i!=j)){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
