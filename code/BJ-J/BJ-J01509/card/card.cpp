#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int main()_{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m,a[N],b[N],c[M];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	long long k=1;
	while(k<=n){
		for(int i=k;i<=n;i++){
			long long s=b.size();
			for(int j=1;j<=s;j++){
				if(a[i]==b[j]){
					for(int v=j+1;v<=s;v++){
							b[v]=0;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=b.size();j++){
				if(b[j]==i) c[i]++;
			}
		}
		k++;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}