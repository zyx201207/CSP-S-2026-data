#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,t=0,t1=0,sum=0;
	string s,b,s2;
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> a >> b;
		t+=a;
		for(int j=0;j<a;j++){
			s+=b;
		}
	}
	for(int i=t-1;i>=0;i--){
		if(s[i]!=s[t1]){
			sum++;
		}
		t1++;
	}
	cout << sum/2;
}
