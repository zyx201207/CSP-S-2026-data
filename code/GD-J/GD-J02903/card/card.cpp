#include<bits/stdc++.h>
using namespace std;
long long t[300005],n,m,a[500005],inf=-9999999,c[300005],p;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	//delete_freopen
	for(int i=0;i<=n+1;i++){
		t[i]=inf;
	}
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		p=1;
		for(int i=0;i<=n+1;i++){
			t[i]=inf;
		}
		for(int j=i;j<n;j++){
			if(t[a[j]]==inf){
				t[a[j]]=p;
				p++;
			}
			else{
				if(t[a[j]]==p-1){
					continue;
				}
				else{
					for(int k=0;k<=m;k++){
						if(t[k]>t[a[j]]){
							t[k]=inf;
						}
					}
					p=t[a[j]]+1;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(t[j]!=inf){
				c[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
