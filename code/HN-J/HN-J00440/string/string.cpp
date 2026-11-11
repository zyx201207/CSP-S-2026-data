#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long a[n];
	char g[n];
	long long ans=0;
	string s;
	bool flag=true,b=true;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>g[i];
		if(i>=1){
			if(g[i]!=g[i-1])
				flag=false;
			if(a[i]!=a[i-1])
				b=false;
		}
		for(long long j=0;j<a[i];j++)
			s+=g[i];
		ans+=a[i];
	}
	if(flag==true)
		cout<<0;
	if(b==true){
		string sa;
		long long out=0,ab;
		long long cnt=0;
		for(int i=0;i<n;i++){
			ab=a[i];
			sa+=g[i];
			out++;
		}
		if(out%2==1){
			for(long long i=out/2+1,j=out/2-1;i<=out-1,j>=0;i++,j--){
				if(sa[i]!=sa[j])
					cnt+=ab;
			}
			cout<<cnt;
			return 0;
		}if(out%2==0){
			for(long long i=out/2,j=out/2-1;i<=out,j>=0;i++,j--){
				if(sa[i]!=sa[j])
					cnt+=ab;
			}
			cout<<cnt;
			return 0;
		}
	}
	if(ans%2==1){
		long long cnt=0;
		for(long long i=ans/2+1,j=ans/2-1;i<=ans-1,j>=0;i++,j--){
			if(s[i]!=s[j])
				cnt++;
		}
		cout<<cnt;
		return 0;
	}if(ans%2==0){
		long long cnt=0;
		for(long long i=ans/2,j=ans/2-1;i<=ans-1,j>=0;i++,j--){
			if(s[i]!=s[j])
				cnt++;
		}
		cout<<cnt;
		return 0;
	}
	return 0;
}

