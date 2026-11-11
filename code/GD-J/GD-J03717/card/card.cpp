#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int maxn=5*1e5+5;
int a[maxn],b[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]==0){
			b[a[i]]++;
		}
		else{
			for(int j=1;j<=m;j++){
				b[m]=0;
			}
			b[a[i]]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
