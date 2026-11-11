#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long n,m,ans,num[MAXN];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
	}
	sort(num+1,num+n+1);
	for(int i=1;i<=n;i++){
		long long t=i,k=m;
		while(t>=1 && k>0){
			k-=num[i]-num[t];
			if(k>=0) t--;
		}
		ans=max(ans,i-t);
	}
	cout<<ans;
} 
