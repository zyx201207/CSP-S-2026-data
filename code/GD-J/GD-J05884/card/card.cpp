#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,l=0;
int a[N],ans[N],b[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		l=0;
		for(int k=i;k<n;k++){
			for(int j=0;j<l;j++){
				if(b[j]==a[k]){
					for(int p=j;p<l;p++){
						b[p]=0;
					}
					l=j;
				}
			}
			b[l++]=a[k];
		}
		for(int j=0;j<l;j++){
			++ans[b[j]];
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
