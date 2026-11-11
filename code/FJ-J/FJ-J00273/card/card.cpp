#include<bits/stdc++.h>
using namespace std;
long long a[100005],c[100005],b[100005];
int n,m;

int main(){
	ios::sync_with_stdio(false);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		b[a[i-1]]--;
		for(int j=n;j>=i;j--){
			c[a[j]]++;
			if(b[a[j]]>=2){
				j=i-1; 
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
	return 0;
} 
