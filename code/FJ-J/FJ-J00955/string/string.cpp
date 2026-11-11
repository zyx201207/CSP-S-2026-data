#include<bits/stdc++.h>
using namespace std;
long long a[300000];
char c[300000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long cnt=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		cnt+=a[i];
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2){
		if(a[1]==a[2]){
			if(c[1]==c[1]){
				cout<<0;
			}else{
				cout<<a[1];
			}
		}else{
			if(c[1]==c[2]){
				cout<<0;
			}else{
				cout<<min(c[1],c[2]);
			}
		}
		return 0;
	}
	long long ans=0;
	string s;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<=s.size()/2-1;i++){
		if(s[i]!=s[s.size()-i-1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
