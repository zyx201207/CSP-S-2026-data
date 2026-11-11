#include <bits/stdc++.h> 
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,a[200100],o=0,m=0;
	char x[200100];
	string s=" ";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>x[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s=s+x[i];
		}
	}
	m=s.size();
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[m-i]){
			o++;
		}
	}
	cout<<o;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
