#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m;
int a[N],_a[N];
int b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=i;j<=n;j++){
			int c=-1;
			_a[cnt++]=a[j];
			for(int k=n;k>j;k--){
				if(a[k]==a[j]){
					c=k;
					break;
				}
			}
			if(c!=-1){
				j+=c-i;
			}
		}
		for(int j=0;j<cnt;j++){
			b[_a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 

