#include<bits/stdc++.h>
using namespace std;
int n,a;
long long ss;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n;
	while(n--){
		cin>>a>>c;
		ss+=a;
		for(int i=0;i<a;i++) s+=c;
	}
	long long ans=0;
	for(int i=0;i<=(ss+1)/2-1;i++){
		if(s[i]!=s[ss-i-1]) ans++; 
	}
	cout<<ans;
	return 0;
}
