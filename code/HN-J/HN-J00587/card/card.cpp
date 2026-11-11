#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[100005],sum[100005];
bool cmp(int a,int b){
	return a==b;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[100005]={};
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			if(a[i]==a[j]&&i!=j){
			    for(int k=i;k<=j;k++){
			    	b[k]=0;
				}
				b[j]=a[j];
				continue;
			}
			else if(j>i+1){
				for(int q=0;q<=j-1;q++){
					if(cmp(a[j-q],a[j])){
						for(int k=j-q;k<=j;k++){
					    	b[k]=0;
						}
						b[j]=a[j];
						break;
					}
				}
			}
		}
		for(int j=i;j<=n;j++){
			sum[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
