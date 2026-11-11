#include<bits/stdc++.h>
using namespace std;

long long n,a,h,cnt;
string c,s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a>>c;
		for(long long j=1;j<=a;j++){
			s+=c;
		}
	}
	h=(s.size()+1)/2;
	if(h%2==0){
		for(long long i=h;i>=0;i--){
			for(long long j=h+1;j<s.size();j++){
				if(s[j]!=s[i]){
					s[j]=s[i];
					cnt++;
				}
			}
		}
	}
	else{
		for(long long i=h-1;i>=0;i--){
			for(long long j=h+1;j<s.size();j++){
				if(s[j]!=s[i]){
					s[j]=s[i];
					cnt++;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
