#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int t1[300010],t2[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			t2[a[j]]++;
			if(t2[a[j]]>1){
				for(int k=1;k<=m;k++)
					t2[k]=0;
				t2[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++)
			if(t2[j]>0)
				t1[j]++;
		for(int j=1;j<=m;j++)
			t2[j]=0;
	}
	for(int i=1;i<=m;i++) cout<<t1[i]<<" ";
}
