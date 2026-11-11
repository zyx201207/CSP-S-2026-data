#include<bits/stdc++.h>
using namespace std;
long long n,m,a[999999],b[999999];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long v=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=v;j++){
			if(b[j]==a[i])break;
		}
	}
	for(int i=1;i<=m;i++){
		long long as=0;
		for(int j=1;j<=n;j++)if(a[j]==b[i])as++;
		cout<<as<<" ";
	}
	return 0;
} 
