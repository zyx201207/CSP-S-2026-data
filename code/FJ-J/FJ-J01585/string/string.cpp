#include <bits/stdc++.h>
using namespace std;
//long long a[200005],awa[200005],l,r,ans,k;
long long len,ans;
string s=" ";
//int n,lawa,rawa;
int n,a[200005];
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		for(int j=1;j<=a[i];j++)
			s+=b[i];
		len+=a[i];
//		awa[i]=awa[i-1]+a[i];
	}
	for(int i=1;i<=(len+1)/2;i++)
		if(s[i]!=s[len-i+1]) ans++;
//	k=(awa[n]+1)/2;
//	l=1,r=a[n];
//	lawa=1,rawa=n;
//	while(lawa<rawa){
//		if(b[lawa]!=b[rawa])
//			if(awa[n]%2==1) ans+=min( min( awa[lawa]-l+1,k-awa[lawa-1]-1 ),min( r-awa[rawa]+a[rawa],awa[rawa]-k ) );
//			else ans+=min( min( awa[lawa]-l+1,k-awa[lawa-1] ),min( r-awa[rawa]+a[rawa],awa[rawa]-k ) );
//		if((awa[lawa]-l+1)<(r-awa[rawa]+a[rawa])){
//			l=awa[lawa]+1;
//			lawa++;
//			r-=a[lawa];
//		}
//		else if((awa[lawa]-l+1)==(r-awa[rawa]+a[rawa])){
//			l=awa[lawa]+1;
//			lawa++;
//			r=awa[rawa]+1;
//			rawa--;//我*，不小心按到浏览器了QAQ 
//		}
//		else if((awa[lawa]-l+1)>(r-awa[rawa]+a[rawa])){
//			rawa--;
//			r=awa[rawa];
//			l+=a[rawa];
//		}
//	}
	cout<<ans;
	return 0;
}
