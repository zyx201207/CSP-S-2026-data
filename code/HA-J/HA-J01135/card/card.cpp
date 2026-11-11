#include<bits/stdc++.h>
using namespace std;
long long a[10000001];
long long b[10000001];
long long c[10000001];
long long ans;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
  for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0;
	bool num=0;
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			b[ans++]=a[i];
		for(int j=1;j<=ans;j++){
			if(a[i]==b[j]){
				num=1;
				ans=j;
				}
			}
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
