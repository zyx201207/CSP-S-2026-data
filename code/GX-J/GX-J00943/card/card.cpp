#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],s,c[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++)cin>>a[i];
	for(long long i=0;i<n;i++){
		s--;
		for(long long j=i;j<n;j++){
			bool v=1;
			for(long long l=0;l<s;l++){
				if(b[l]==a[j]){
					v=0;
					for(long long f=l;f<s;f++)b[f]=0;
					s=l-1;
					break;
					}
			}
			if(v)b[s]=a[j];
			s++;
			}
			for(long long j=0;j<s;j++)c[b[j]]++;
		}
		for(long long i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
	}
