#include<bits/stdc++.h>
using namespace std;
int l[500005],bj[500005],ans[500005],n,m;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	for(int i=1;i<=n;i++){
		int temp=i;
		memset(bj,0,sizeof(bj));
		for(;temp<=n;){
			int wte=temp+1,f=0;
			for(;wte<=n;wte++){
				if(l[temp]==l[wte]){
					f=wte;
				}
			}
			bj[l[temp]]=1;
			if(f){
				temp=f+1;
			}
			else{
				temp++;
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=bj[j];
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
