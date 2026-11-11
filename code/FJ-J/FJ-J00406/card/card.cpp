#include<bits/stdc++.h>
using namespace std;
queue<int> n_card;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	int a[n+5];for(int i=0;i<n;i++)cin>>a[i];
	bool z[n+5]={false};for(int i=0;i<n;i++)z[i]=false;
	int ans[m];for(int i=0;i<m;i++)ans[i]=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			while((int)n_card.size()>-1 && z[a[j]]==true){
				int t=n_card.front();
				z[t]=false;
				n_card.pop();
			}
			n_card.push(a[j]);
			z[a[j]]=true;
		}
		while(!n_card.empty()){
			int t=n_card.front();
			ans[t-1]++;
			cout<<t<<" ";
			n_card.pop();
		}
		cout<<endl;
	}
	for(int i=0;i<m;i++)cout<<ans[i]<<" ";
	return 0;
}
