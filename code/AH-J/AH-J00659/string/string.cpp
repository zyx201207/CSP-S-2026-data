#include<bits/stdc++.h>
using namespace std;
long long p,n,k,v;
long long sum=0,ans;
string a,b;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>k>>b;
		sum+=k;
		for(long long j=1;j<=k;j++){
			a+=b;
		}
	}
	sum--;
	int m=-1,n=sum+1;
	while(m<=n){
		m+=1;
		n-=1;
		if(a[m]==a[n]){
			continue;
		}else{
			 a[n]=a[m],ans++;
		}
	}
	cout<<ans;
}
