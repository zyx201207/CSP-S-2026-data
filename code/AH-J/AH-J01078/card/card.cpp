#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ans[300010];
bool b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		memset(b,1,n);
		for(int j=n-1;j>=i;j--){
			if(!b[j])continue;
			for(int k=i;k<j;k++){
				if(a[k]==a[j]){
					if(j>0)memset(b,0,j);
					if(k>0)memset(b,1,k);
					break;
				}
			}
		}
		for(int j=i;j<n;j++){
			if(b[j]){
				ans[a[j]-1]++;
			}
		}
	}
	for(int i=0;i<m;i++)
		cout<<ans[i]<<endl;
	return 0;
}
