#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	string s;
	for(int i=1;i<=n;i++){
		long long a;
		string c;
		cin>>a>>c;
		while(a--){
			s+=c;
		}
	}
	long long cnt=0;
	for(int i=(s.size()+1)/2;i<=s.size();i++){
		if(s[i]!=s[(s.size()+1)/2-i+1]){
			s[i]=s[(s.size()+1)/2-i+1];
			cnt++;
		}
	}
	printf("%lld",cnt);
	return 0;
} 
