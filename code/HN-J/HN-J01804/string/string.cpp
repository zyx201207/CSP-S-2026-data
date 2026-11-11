#include<bits/stdc++.h>
using namespace std;
const int N=1e8+4;
int a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long L=0;
	for(int i=1;i<=n;i++){
		long long x;
		char p;
		cin>>x>>p;
		int t=p-'a';
		for(long long j=L+1;j<=L+x;j++){
			a[j]=t;
		}
		L+=x; 
	}
	long long ans=0;
	long long k;
	if(L%2) k=L/2+1;
	else k=L/2;
	for(long long  i=1;i<=k;i++){
		if(a[i]!=a[L+1-i]){
		ans++;
		}
		
	}
	cout<<ans;
}
