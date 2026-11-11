#include<bits/stdc++.h>
using namespace std;

int n,m,a[500050];
int b[500050],br;//stact;
int cnt[500050];

int main(){
//	freopen("card.in","w",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		br=1;
		for(int j=i;j<=n;j++){
			for(int o=1;o<=br;o++){
				if(b[o]==a[j]){
					br=o;
					break;
				}
			}
			b[br++]=a[j];
		}
		for(int j=1;j<br;j++){
			cnt[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;           
}