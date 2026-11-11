#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],b[500010]={0},d[300010]={0},s[300010]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			if(d[a[j]]!=0){
				b[d[a[j]]]=-1;
				d[a[j]]=j;
			}
			if(d[a[j]]==0){
				d[a[j]]=j;
			}
		}
		int t[m+10]={0};
		for(int j=i;j<=n;j++){
			if(b[j]!=-1){
				t[b[j]]=1;
			}
			if(b[j]==-1){
				int x=j;
				do{
					j++;
				}
				while(b[j+1]!=a[x]);
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]==1){
				s[j]++;
			}
			d[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<s[i]<<' ';
	}
	return 0;
}
