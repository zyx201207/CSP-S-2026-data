#include<bits/stdc++.h>
using namespace std;
string s,o;
long long n,a[10010],ans;
int o1,os=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
	cin>>o1;
	cin>>o;	
	for(int j=0;j<o1;j++){
		s[os]=o[0];
		os++;
		}
	}
	int j=n;
	for(int i=0;i<n;i++){
		j--;
		if(i==j) continue;
		if(s[i]!=s[j]){
		 ans++;
		 }
		
	}
	cout<<ans;
	return 0;
}
