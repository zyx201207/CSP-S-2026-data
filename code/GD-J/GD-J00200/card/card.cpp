#include<bits/stdc++.h>
using namespace std;
int a[500005],v[500005],v2[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		v[a[i]]=i;
	}
	int l;
	for(int i=1;i<=n;i++){
		l=i;
		while(l<=n){
			v2[a[l]]++;
			if(v[a[l]]==i) l++;
			else{
				l=v[a[l]]+1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<v2[i]<<' ';
	}
	return 0;
}

