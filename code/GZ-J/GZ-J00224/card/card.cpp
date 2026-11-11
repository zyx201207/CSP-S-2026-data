//GZ-J00224 Í¿Ðù½Ü 
#include<bits/stdc++.h>
using namespace std;
int a[500005];
int t[500005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		memset(t,0,sizeof(t));
		int p=0;
		for(int j=i;j<n;j++){
			bool y=1;
			for(int k=0;k<n;k++){
				if(t[k]==a[j]){
					y=0;
					p=k;
				}
				t[k]*=y;
			}
			t[p++]=a[j];
		}
		for(int j=0;j<p;j++)ans[t[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	cout<<endl;
	return 0;
}
