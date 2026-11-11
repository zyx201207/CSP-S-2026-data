#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[500005];
int f[500005];
int cnt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	int maxn=a[n];
	for(int i=1;i<=n;i++){
		int ys=i-1;
		int s=1;
		while(ys>=f[s]){
			ys-=f[s];
			s+=1; 
		}
		for(int i=s;i<=m;i++){
			if(f[i]!=0){
				cnt[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
