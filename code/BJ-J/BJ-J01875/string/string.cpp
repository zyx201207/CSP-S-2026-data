#include<bits/stdc++.h>
using namespace std;
long long n,ans;
string s;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;
		char b;
		cin>>a>>b;
		while(a--){
			s+=b;
		}
	}
	long long i=0,j=s.size();
	while(i<=j){
		if(s[i]==s[j]){
			i++;
			j--;
			continue;
		}else{
			s[j]=s[i];
			ans++;
			i++;
			j--;
			continue;
		}
	}
	cout<<ans;
    return 0;
}
