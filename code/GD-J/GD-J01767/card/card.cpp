#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],et[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int nw[500004],ni=i;
		bool t[300006];
		for(int j=i;j<=n;j++){
			if(!t[a[j]]){
				t[a[j]]=1;
				nw[ni]=a[j];
				ni++;
			}else{
				for(int k=i;k<ni;k++){
					if(nw[k]==a[j]){
						for(int L=k;L<ni;L++){
							t[nw[L]]=0;
							nw[L]=0;
						}
						ni=k;
						break;
					}
				}
				nw[ni]=a[j];
				t[a[j]]=1;
			}
		}
		for(int j=i;j<=m;j++){
			if(t[j]) et[j]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<et[i]<<" ";
	return 0;
}
