#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],s[300005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(s[a[j]]!=0){
				for(int k=s[a[j]];k<j;k++)
					if(s[a[k]]!=0)
						d[a[k]]--,s[a[k]]=0;
			}s[a[j]]=j,d[a[j]]++;
		}for(int j=1;j<=m;j++)
			s[j]=0;
	}for(int i=1;i<=m;i++)
		cout<<d[i]<<" ";
	return 0;
}
