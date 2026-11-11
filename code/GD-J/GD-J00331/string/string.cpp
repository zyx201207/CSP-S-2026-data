#include <bits/stdc++.h>
using namespace std;
string s,k1,k2; 
char c;
long long sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++) s+=c;
	}
	if(s.size()%2==1){
		long long r=s.size()/2;
		for(long long i=0;i<r;i++){
			k1+=s[i];
		}
		for(long long i=s.size()-1;i>r;i--){
			k2+=s[i];
		}
	}
	else if(s.size()%2==0){
		for(long long i=0;i<s.size()%2;i++){
			k1+=s[i];
		}
		for(long long i=s.size()-1;i>s.size()%2;i--){
			k2+=s[i];
		}
	}
	for(long long i=0;i<k1.size();i++){
		if(k1[i]!=k2[i]) sum++;
	}
	cout<<sum;
	return 0;
}
