#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ton[300005];
int pd[500010];
int pos[300005];//值为i的牌在pos[i] 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int idx;
	for(int i=1;i<=n;i++){
		idx=0;
		for(int j=1;j<=m;j++){
			pos[j]=0;
		}
		memset(pd,0,sizeof(pd));
		for(int j=i;j<=n;j++){
			if(pos[a[j]]>0){
				idx=pos[a[j]]-1;
			}
			idx++;
			pd[idx]=a[j];
			pos[a[j]]=idx;
		}
		for(int j=1;j<=idx;j++){
			ton[pd[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ton[i]<<' ';
	}
	return 0;
}
