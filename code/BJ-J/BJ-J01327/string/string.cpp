#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	long long sum=0;
	bool b=0,bb=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		if(a[i]!=a[i-1]&&i>=2) b=1;
		if(c[i]!=c[i-1]&&i>=2) bb=1;
	}
	long long ans=0;
	if(b==0) {
		for(int i=1;i<=n/2;i++){
			if(c[i]!=c[n-i+1]) ans+=a[i];
		}
		cout<<ans<<endl;
	}
	else if(bb==0){
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			
			while(a[i]) a[i]--,s+=c[i];
		}
		long long aa=sum/2;
		//for(long long i=1;i<=aa;i++){
		//	if(c[i]!=c[sum-i+1]) ans++;	
		//}
		/*long long ss=0,q;
		for(long long i=1;i<=n;i++){
			ss+=a[i];
			if(ss>=aa){
				q=i;
				break;
			}
		}
		long long k=ss-aa;
		for(long long i=1;i<=q;i++){
			if(c[i]!=c[n-i+1]) ans+=a[n-i+1];
		}
		cout<<ans<<endl;*/
		for(long long i=1;i<=aa;i++){
			if(s[i]!=s[sum-i+1]) ans++;	
		}
		cout<<ans<<endl;
	}
	return 0;
}
