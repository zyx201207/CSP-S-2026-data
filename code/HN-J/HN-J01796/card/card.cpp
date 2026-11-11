#include<bits/stdc++.h>
using namespace std;
long long b[100000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long a[n+1],k[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		for(long long j=i;j<=n;j++){
			k[j]=a[j];
		}
		for(long long j=i;j<=n;j++){
			for(long long u=i;u<j;u++){
				if(k[u]==k[j]){
					for(long long q=u;q<j;q++){
						k[q]=0;
					}
				}
			}
		}
		for(long long j=i;j<=n;j++){
			b[k[j]]++;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<b[i];
		if(i!=m){
			cout<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
