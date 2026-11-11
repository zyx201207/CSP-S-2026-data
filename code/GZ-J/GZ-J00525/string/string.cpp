//GZ-J00525 兴义市弘毅中学 龙乙夫
#include<bits/stdc++.h>
using namespace std;
long long const MAXN=2*1e5+5;
long long n;
string s;
long long le[MAXN],sum[MAXN]={0};char c[MAXN];

int main(){
	freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>le[i]>>c[i];
		sum[i]=sum[i-1]+le[i];
	}for(long long i=1;i<=n;i++){
		for(long long j=0;j<le[i];j++){
			s.push_back(c[i]);
		}	
	}
	long long len=s.size();
	string h[2];
	h[0]=s.substr(0,len/2);
	h[1]=s.substr(len/2+(len%2==1),len/2);
	long long ans=0;
	for(long long i=0;i<len/2;i++){
		ans+=(h[0][i]!=h[1][i]);
	}
	cout<<ans<<endl;
	return 0;
}
