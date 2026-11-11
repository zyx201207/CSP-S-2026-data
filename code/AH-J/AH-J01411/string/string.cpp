#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long a[N],n,q=0,ans=0,cnt=0;
bool f=0;
string s,s1,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}for(long long i=0;i<n;i++){
		s+=b[i];
		cnt+=a[i];
	}for(long long i=s.size()-1;i>=0;i--){
		s1+=b[i];
	}if(s1==s){
		cout<<0;
		f=1;
	}if(n%2==0){
		for(long long i=0;i<n/2;i++){
			s1[i]=s[i];
			q++;
		}for(long long i=n/2-1;i>=0;i--){
			s1[q++]=s[i];
		}for(long long i=0;i<n;i++){
			if(s[i]!=s1[i]) ans+=a[i];
		}
	}else{
		for(long long i=0;i<=n/2;i++){
			s1[i]=s[i];
			q++;
		}for(long long i=n/2-1;i>=0;i--){
			s1[q++]=s[i];
		}for(long long i=0;i<n;i++){
			if(s[i]!=s1[i]) ans+=a[i];
		}if(a[n/2]%2==0) ans+=a[n/2]/2;
		else ans+=a[n/2]/2;
	}if(f!=1) cout<<ans;
	return 0;
}
