#include<bits/stdc++.h>
using namespace std;
long long n,x,ans;
string t;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			t+=c;
		}
	}
	long long k=t.size();
	if(k%2==0){
		long long l=k/2,r=k/2+1;
		for(long long i=1;i<=k/2;i++){
			if(t[l]!=t[r]) ans++;
			l--;r++;
		}
	}
	else {
		long long l=k/2,r=k/2+2;
		for(long long i=1;i<=k/2;i++){
			if(t[l]!=t[r]) ans++;
			l--;r++;
		}
	}
	cout<<ans;
	return 0;	
}