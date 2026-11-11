#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int u=n;
	long long ans=0,ned=0;
	for(int i=0;i<=n/2+1;){
		if(ned==0){
			i++;
			ned=a[i];
		}
		if(a[u]==0) u--;
		if(c[i]!=c[u]){
			if(ned>a[u]){
				ans+=a[u];
				ned-=a[u];
				a[u]=0;
			}else{
				ans+=ned;
				a[u]-=ned;
				ned=0;
			}
		}else if(c[i]==c[u]){
			if(ned>a[u]){
				ned-=a[u];
				a[u]=0;
			}else{
				a[u]-=ned;
				ned=0;
			}
		}
	}
	cout<<ans;
	return 0;
}
