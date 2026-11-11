#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	bool t=1;
	for(long long i=2;i<=n;i++){
		if(b[i]!=b[i-1]){
			t=0;
		}
	}
	if(t==1){
		cout<<0;
		return 0;
	}
	long long sum=a[1];
	bool f=1;
	for(long long i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			f=0;
			break;
		}
		sum+=a[i];
	}
	if(f){
		cout<<sum/2;
		return 0;
	}
	string s=" ";
	for(long long i=1;i<=n;i++){
		while(a[i]>0){
			s+=b[i];
			a[i]--;
		}
	}
	int len=s.size();
	int ans=0;
	for(int i=1;i<=len/2;i++){
		if(s[i]!=s[len-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
