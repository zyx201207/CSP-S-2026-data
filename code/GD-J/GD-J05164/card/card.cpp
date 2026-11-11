#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],am[300001];
bool b[300001];
long long bb[300001];
vector<long long> v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		bool b[300001];
		for(int p=1;p<=m;p++){
			bb[p]=0;
		}
		for(int k=i;k<=n;++k){
			if(b[a[k]]==true){
				for(int j=bb[a[j]];j<=k;j++){
					b[j]=false;
					bb[a[j]]=j;
				}
			}
			b[a[k]]=true;
			bb[a[k]]=k;
		}
		for(int j=1;j<=m;j++){
			if(b[j]==true){
				am[j]++;
			}
		}
	}	
	for(int j=1;j<=m;j++){
		cout<<am[j]<<" ";
	}	
}
