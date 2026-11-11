#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long a,b,s[100100],w[100100],ans=0;
	cin>>a>>b;
	for(long long i=1;i<=a;i++){
			cin>>s[i];
		}
	for(long long i=s[1];i<=s[a];i++){
		long long q=b,e=0;
		for(long long j=1;j<=a;j++)w[j]=s[j];
		for(long long j=a;j>=1;j--){
				if(q>=i-w[j]&&w[j]<=i){
					q-=i-w[j];
					e++;
				}
		}
		ans=max(ans,e);
	}
	cout<<ans;
	return 0;
}
