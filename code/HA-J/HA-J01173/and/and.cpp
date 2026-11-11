#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
long long s[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,maxn=0,ans=0;
	cin>>n>>m;
	cin>>s[1];
	maxn=s[1];ans=s[1];
	for(int i=2;i<=n;i++){
		cin>>s[i];
		maxn=max(maxn,s[i]);
		ans=ans&s[i];
	}
	if(m==1){
		cout<<maxn;
	}else if(m==n){
		cout<<ans;
	}else if(m==2){
		maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=1+i;j<=n;j++){
				maxn=max(maxn,s[i]&s[j]);	
			}
		}
		cout<<maxn;
	}else if(m==n-1){
	long long d=0;
		for(int i=1;i<=n;i++){
			d=0;
			for(int j=1;j<=n;j++){
				if(j!=i){
					if(d==0)d=s[j];
					else d=d&s[j];	
				}
			}
			maxn=max(maxn,d);
		}
		cout<<maxn;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
