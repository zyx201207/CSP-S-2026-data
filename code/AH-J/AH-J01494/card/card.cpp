#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001],s[500001],t[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			for(long long k=i;k<j;k++){
				if(s[k]==a[j]){
					for(long long e=k;e<j;e++){
						s[e]=-1;
					}
					break;
				}
			}
			s[j]=a[j];
		}
		for(long long j=n;j>=i;j--){
			if(s[j]==-1) continue;
			t[s[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}
