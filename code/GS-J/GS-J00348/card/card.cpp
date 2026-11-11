#include<bits/stdc++.h>
using namespace std;
int card[500000+10],t[300000+10],ans[500000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n=0,m=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[i];
	}
	for(int i=1;i<=n;i++){
		int p=1;
		for(int j=i;j<=n;j++){
			bool ok=true;
			int q=0;
			for(int k=1;k<=p;k++){
				if(t[k]==card[j]){
					ok=false;
					q=k;
					break;
				}
			}
			if(!ok){
				p=q;
			}
			t[p]=card[j];
			p++;
		}
		for(int j=1;j<p;j++){
				ans[t[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
	return 0;
}
