#include<bits/stdc++.h>
using namespace std;
string s=" ";
long long n,a[1000000005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char c;
		cin>>a[i]>>c;
		for(int j=1;j<=a[i];j++){
			s+=c;
		}
	} 
	for(int i=1;i<=s.size()/2;i++){
		if(s[i]!=s[s.size()-i]){
			sum++;
		}
	} 
	cout<<sum;
	return 0;
}
