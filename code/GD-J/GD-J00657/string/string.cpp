#include<bits/stdc++.h> 
using namespace std;
long long n,a[200005],ans;
char c[200005];
string s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i]>>c[i];
	for(long long i=0;i<n;i++){
		for(long long j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	//cout<<s<<endl;
	//for(int i=s.size()-1;i>=0;i--) s1+=s[i];
	bool b=0;
	for(long long i=0;i<n-1;i++){
		if(a[i]==a[i+1]) b=1;
		else{
			b=0;
			break;
		}
	}
	if(b){
		long long l1=n/2;
		for(long long i=0;i<l1;i++){
			if(c[i]!=c[n-1-i]) ans+=a[i]; 
		}
	}else{
		long long l=s.size()/2;
		for(long long i=0;i<l;i++){
			if(s[i]!=s[s.size()-1-i]) ans++; 
		}	
	}
	cout<<ans;
	return 0;
}
