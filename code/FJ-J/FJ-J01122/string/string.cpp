#include <bits/stdc++.h> 
using namespace std;
long long n,a,sum=0,t;
string s,r,h;
char b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		for(int j=1;j<=a;j++){
			s+=b;
		}
	}
	if(s.size()%2!=0){
		t=s.size()/2-1;
		for(int i=0;i<=t;i++){
			r+=s[i];
		}
		for(int i=s.size()-1;i>t+1;i--){
			h+=s[i];
		}
		for(int i=0;i<=t;i++){
			if(r[i]!=h[i]){
				sum++;
			}
		}
	}else{
		t=s.size()/2;
		for(int i=t-1;i>=0;i--){
			r+=s[i];
		}
		for(int i=t;i<=s.size();i++){
			h+=s[i];
		}
		for(int i=0;i<=t;i++){
			if(r[i]!=h[i]){
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}

