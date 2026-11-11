#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
long long a[M],a1[M]={-1},ss[M],sss[M];
char b[M],b1[M]={' '};
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	bool f=1;
	long long n,ans=0,sum=0,cnt=1;cin>>n;
	string s="";
	for(long long i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]>1e7){
			f=0;
		}
		ss[i]=ss[i-1]+a[i];
		sum+=a[i];
	}
	for(long long i=n;i>=1;i--){
		sss[i]=sss[i+1]+a[i];
	}
//	for(long long i=1;i<=n;i++){
//		cout<<ss[i]<<' '<<sss[i]<<"\n";
//	}
/*	if(n>2e3){
		f=0;
	}
	if(f==1){
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=a[i];j++){
				s+=b[i];
			}
		}
		for(long long i=0;i<sum/2;i++){
			if(s[i]!=s[sum+1-i]){
				ans++;
			}
		}
		cout<<ans;
		return 0;
	}else{*/
		int j=1,j1=n;
		for(long long i=1;i<sum/2+1;i++){
			if(i<=ss[j]){
				if(i>sss[j1]){
					j1--;
				}
			}else{
				j++;
				if(i>sss[j1]){
					j1--;
				}
			}
			if(b[j]!=b[j1]){
				ans++;
			}
//			cout<<i<<' '<<j<<' '<<j1<<' '<<ans<<"\n";
		}
		cout<<ans;
//	}
	/*(long long i=1;i<=n;i++){
		if(a1[1]==-1&&b1[1]==' '){
			if(a[i]==a[n+1-i]){
				if(b[i]!=b[n+1-i]){
					ans+=a[n+1-i];
				}
			}else{
				if(b[i]!=b[n+1-i]){
					a1[1]=max(a[i],a[n+1-i])-min(a[i],a[n+1-i]);
					if(a1[1]==a[i]){
						b1[1]=b[i];
					}else{
						b1[1]=b[n+1-i];
					}
					ans+=min(a[i],a[n+1-i]);
				}else{
					a1[1]=max(a[i],a[n+1-i])-min(a[i],a[n+1-i]);
					if(a1[1]==a[i]){
						b1[1]=b[i];
					}else{
						b1[1]=b[n+1-i];
					}
					ans+=max(a[i],a[n+1-i])-min(a[i],a[n+1-i]);
				}
			}
		}else{
			
		}
	}

	cout<<ans;*/
	return 0;
}
