#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],f[500005],ans[500005];
stack<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			if(f[a[j]]==1){
				while(s.top()!=a[j]){
					f[s.top()]--;
					s.pop();
				}
				f[a[j]]=1;
			}else{
				s.push(a[j]);
				f[a[j]]=1;
			}
		}
		for(int k=1;k<=m;k++){
			if(f[k]==1){
				ans[k]++;
			}
		}
		while(!s.empty()){
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}	
    return 0;
}
