#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000];
long long cnt[10000];
long long sum=0;
long long ans=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int sy=0;
	int v=1;
	cin>>n>>m;
	long long s=(n*(n-1))/2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=s;i++){
			cnt[j]=(abs(a[v]-a[j+1]));
			if(j>(n-1)){
				v++;
				j=v;
			}
			while(j!=s){
				sum+=cnt[j];
				if(sum==m){
					while(j!=s){
						if(cnt[j]==cnt[j+1]){
							ans++;
						}
						j++;
					}
					if(sum>m){
						break;
					} 
					sum=0;
					j++;
				}
			}
		}
		
	}
	cout<<ans+1;
	return 0;
} 
