#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long len,ans,s[N],sb[N];
int a[N],n;
char c[N]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&a[i],&c[i]);
		len+=a[i];
		s[i]=s[i-1]+a[i];
//		cout<<s[i]<<"¡¡"; 
	}
	for(int i=n;i>0;i--){
		sb[i]=sb[i+1]+a[i];
//		cout<<sb[i]<<" ";
	}
	long long l=1,r=1;
	for(int i=1,j=n;;){
//		cout<<i<<" "<<j<<":"<<endl; 
		long long k=min(s[i]-l+1,sb[j]-r+1);
		if(c[i]!=c[j]) ans+=k;
		l+=k,r+=k;
		if(s[i]-l+1 > sb[j]-r+1) j--;
		else if(s[i]-l+1 < sb[j]-r+1) i++;
		else i++,j--; 
		if(i>=j) break;
	}
	printf("%lld",ans);
	return 0;
}

