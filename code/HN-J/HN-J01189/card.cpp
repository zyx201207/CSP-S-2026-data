#include <bits/stdc++.h>
using namespace std;
const int MAXN=500005;
long long a[MAXN];
int ans[MAXN];
void play(int x){
	int l[MAXN]={};
	for(int j=x;j<=n;j++){
		for(int k=1;k<=j-X;k++){
			if(l[k]==a[j]){
				for(int r=k+1;r<=j-1;r++){
					l[r]=0;
				}
				break;
			}
		}
		l[j-x+1]=a[j];
	}
	for(int j=1;j<=n;j++){
		ans[l[j]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		play(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
