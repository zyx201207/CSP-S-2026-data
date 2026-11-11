#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	char c;
	long long t=0;
	int n,b;
	cin >> n ;
	for(int i=1;i<=n;i++){
		cin >>b>>c;
		for(int j=i;j<=b;j++){
			s+=c;
		}
	}
	for(int i=0;i<=s.size()/2;i++){
		if(s[i]!=s[n-1]){
			t++;
		}
	}
	cout<<t<<endl;
	return 0;
}