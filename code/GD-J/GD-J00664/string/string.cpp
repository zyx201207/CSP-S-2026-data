#include<bits/stdc++.h>
using namespace std;
string s;
bool func(string x){
	string y;
	int l=x.size();
	for(int i=l-1; i>=0; i--){
		y+=x[i];
	}
	for(int i=0; i<l; i++){
		if(x[i]!=y[i]){
			return 0;
		} 
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		long long a;
		string c;
		cin>>a>>c;
		for(int j=1; j<=a; j++){
			s+=c;
		}
	}
	if(n==1){
		printf("0");
		return 0;
	}
	if(func(s)){
		printf("0");
	}else{
		string t;
		int l=s.size();
		for(int i=l-1; i>=0; i--){
			t+=s[i];
		}
		long long cnt=0;
		for(int i=0; i<=l/2; i++){
			if(s[i]!=t[i]){
				cnt++;
			}
		}
		printf("%lld",cnt);
	}
	return 0;
}
