#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005],b[100001];
long long c[1000001];
long long sum;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=0;
	bool f=0;
	for(int k=1;k<=n;k++){
		for(int i=k;i<=n;i++){
			b[++cnt]=a[i];
			for(int j=1;j<=cnt;j++){
				if(a[i]==b[j]){
					f=1;
					cnt=j;
				}
			}
		}
		for(int i=1;i<=cnt;i++){
			c[b[i]]++;
		}
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
