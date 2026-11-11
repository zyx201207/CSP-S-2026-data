#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ji[300010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		int lu[300010]={0};
		for(int i=k;i<=n;i++){
			if(lu[a[i]]>0){
				int flag=0;
				for(int j=k;j<i;j++){
					if(a[j]==a[i]) flag=1;
					if(flag==1) lu[a[j]]-=1;
				}
			}
			lu[a[i]]+=1;
		}
		for(int i=1;i<=m;i++) if(lu[i]>0) ji[i]+=1;
	}
	for(int i=1;i<=m;i++) cout<<ji[i]<<" ";
	return 0;
}
