#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
long long n,a[N],ans,cnt,tt,hh,as[N];
char c[N],st[N];
string s,t;


int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		as[i]=as[i]+a[i];
	}
	for(long long i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	for(long long i=0,j=s.size()-1;i<s.size()&&j>=0;i++){
		if(s[i]!=s[j]){
			ans++;
			i++;
			j--;
		}else{
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}

