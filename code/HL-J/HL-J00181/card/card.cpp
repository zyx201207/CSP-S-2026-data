#include<bits/stdc++.h>
using namespace std;

int n,m,aa[500005],ans[500005];
bool h[500005];
stack<int> a;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>aa[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(h[aa[j]]==1){
				while(a.top()!=aa[j]){
					h[a.top()]=0;
					a.pop();
				}
			}else{
				a.push(aa[j]);
				h[aa[j]]=1;
			}
		}
		while(!a.empty()){
			ans[a.top()]++;
			a.pop();
		}
		memset(h,0,sizeof(h));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}


    return 0;
}
