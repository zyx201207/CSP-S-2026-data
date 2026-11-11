#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long n,ans=0,q=0;
	string e="0";
	string s;
	long long a[200001];
	string c[200001];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	q=a[1];
	e=c[1];
	if(n%2==0){
		string p=c[n/2+1];
		bool z=0;
		for(int i=2;i<=n;i++){
			if(a[i]!=q)z=1;
		}
		for(int i=2;i<=n/2;i++){
			if(c[i]!=e)z=1;
		}
		for(int i=n/2+2;i<=n;i++){
			if(c[i]!=p)z=1;
		}
		if(!z){
		cout<<a[1]*n/2;
		return 0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
		if(s.size()%2==1){
			int i=0;
			while(i!=s.size()-i-1){
				if(s[i]!=s[s.size()-i-1]){
				ans++;
				}
			i++;
			}
		}else{
			int i=0;
			while(i-1!=s.size()-i+1){
				if(s[i]!=s[s.size()-i-1]){
					ans++;
				}
				i++;
			}
		}
		cout<<ans;
	return 0;
}
