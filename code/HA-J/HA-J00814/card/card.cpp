#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],ans[100005],stk[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int last=0;
		int b[200005]={};
//		cout<<endl<<i<<endl;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=++last;
				stk[last]=a[j];
			}
			else{
				for(int k=b[a[j]]+1;k<=last;k++){
					b[stk[k]]=0;
				}
				last=b[a[j]];
				stk[last]=a[j];
			}
//			for(int i=1;i<=last;i++){
//				cout<<b[stk[i]]<<' ';
//			}cout<<endl;
		}
		while(last>0){
			ans[stk[last]]++;
			last--;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
