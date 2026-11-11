#include<bits/stdc++.h>
using namespace std;
int a[5002],sum[3002],c[5002],t=0;
bool b[3002];
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){	
				b[a[j]]=1;
			}
			else{
				b[a[j]]=0;
				while(t!=0 && c[t]!=a[j]){
					t--;
				}
				t--;
			}
			c[++t]=a[j];
		}
		while(t!=0){
			sum[c[t]]+=1;
			cout<<sum[c[t]]<<' '<<c[t]<<endl;
			t--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
