#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cnt++;
		cin>>a[cnt];
		for(int j=1;j<cnt;j++){
			if(a[cnt]==a[j])cnt=j+1;
		}
		//cout<<x<<" ";
	}for(int i=1;i<=cnt;i++)cout<<a[i]<<" ";
	return 0;
} 
