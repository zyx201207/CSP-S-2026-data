#include<bits/stdc++.h>
using namespace std;
long long n,m,l=0,a[10001],s[10001],p[10001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n-l;j++){
			long long b=0;
			s[j]=a[j+l];
			for(long long k=1;k<=j;k++){
				if(s[j]==s[k]){
					b=1;
				}
			}
			if(b==1){
				for(long long k=1;k<=j;k++){
					s[k]=0;
				}
			}
		}
		for(long long j=1;j<=n;j++){
			if(s[j]!=0){
				long long b;
				for(long long k=1;k<=j;k++){
					if(s[j]==s[k]){
						b=1;
					}
				}
				if(b==0){
					p[b]++;
				}
			}
		}
		l++;
	}
	for(long long i=1;i<=m;i++){
		cout<<p[i]<<' ';
	}
	return 0;
}
