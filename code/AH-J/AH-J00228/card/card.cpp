#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500050],cnt[300050],dq[300050],q;
bool o[300050];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	q=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=n;j++){
		q=1;
		for(int i=j;i<=n;i++){
			dq[q]=a[i];
			if(o[a[i]]==1){
				do{
					o[dq[q]]=0;
					dq[q]=0;
					q--;
				}while(dq[q]!=a[i]);
			}
			o[a[i]]=1;
			q++;
		}
		for(int i=1;i<=m;i++){
			if(o[i]==1)  cnt[i]++;
			o[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
}
