#include <bits/stdc++.h>
using namespace std;
int a[500005],s[500005],an[300005],sa[300005];
bool out[300005];
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
		for(int j=i;j<=n;j++){
			if(out[a[j]]){
				for(int k=sa[a[j]];k<=j;k++){
					out[a[k]]=0;
				}
			}
			out[a[j]]=1;
			sa[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(out[m]){
				an[m]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<an[m];
	}
	return 0;
}
