#include<bits/stdc++.h>
using namespace std;
long long n,cnt,ans=0;
int a[200005];
bool f[200005];
char s[200005];
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		int x;
		char c;
		cin>>x>>c;
		a[i]=x;
		s[i]=c;
	}
	int m=n;
	for(int i=1;i<=n/2;++i){
		for(int j=m;j>n/2;--j){
			if(!a[i]||!a[j])continue;
			if(f[i]||f[j]) continue;
			if(s[i]!=s[j]){
				if(a[i]>=a[j]){
					//m=j-1;
					f[j]=1;
					s[j]=s[i];
					a[i]-=a[j];
					ans+=a[j];
				}
				else{
					//m=j;
					f[i]=1;
					s[i]=s[j];
					a[j]-=a[i];
					ans+=a[i];
					j++;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


