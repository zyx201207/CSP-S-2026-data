#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[100005];
long long jl[1000005];
long long szj[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","W",stdout);
	cin>>n>>m;//4 3
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int js=1;
	while(js!=n+1){
		long long zp[100005]={0};
		long long t[100005]={0};
		long long xb=0;
		for(long long i=js;i<=n;i++){
			xb++;
			zp[xb]=a[i];
			t[zp[xb]]++;
			if(t[zp[xb]]>1){
				t[zp[xb]]=0;
				for(long long j=1;j<=i;j++){
					if(zp[j]==zp[xb]){
						for(int k=j;k<i;k++){
							zp[k]=0;
						}
					}
				}
			}
		}
		//for(int i=1;i<=xb;i++)	cout << zp[i] << " ";
		//cout << endl;
		for(long long i=1;i<=m;i++){
			for(long long j=1;j<=xb;j++){
				if(zp[j]==i){
					szj[i]++;
				}
			}
		}
		js++;
	}
	
	for(int i=1;i<=m;i++){
		if(a[n]==i) cout << n << " ";
		else cout << szj[i] << " ";
	}
}
