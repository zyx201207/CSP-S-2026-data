#include<bits/stdc++.h>
using namespace std;
int n,m,flag[300010],a[500010],b[300010],k[500010],l=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int y=1;y<=n;y++){
		for(int i=y;i<=n;i++){
			if(flag[a[i]]==0){
				k[l]=a[i];
				l++;
				flag[a[i]]=1;
			}
			else{
				int j=1;
				while(k[j]!=a[i]){
					j++;
				}
				for(int p=j+1;p<=l;p++){
					flag[k[p]]=0;
					k[p]=0;
				}
				l=j+1;
			}
		}
		//for(int j=1;j<l;j++) //cout<<k[j]<<' ';
		//cout<<endl;
			for(int t=1;t<=m;t++){
				if(flag[t]==1) b[t]++;
			}
	}
	for(int i=1;i<=m;i++)
	cout<<b[i]<<' ';
	return 0;
}
