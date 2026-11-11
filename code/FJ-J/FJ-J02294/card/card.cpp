#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int w[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	int t=n;
	while(t--){
		for(int i=0;i<=n;i++){
			b[i]=0;
		}
		int now=0;
		for(int i=1;i<=n;i++){
			++now;
			b[now]=w[i];
			int flag=1,s=now;
			for(int j=1;j<=now;j++){
				if(flag==-1){
					b[j]=0;
					continue;
				}
				if(b[j]==b[now] && j!=now){
					s=j;
					flag=-1;
				}
			}
			now=s;
		}
		for(int i=1;i<=now;i++){
			a[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<a[i]<<' ';
	}
	return 0;
}
