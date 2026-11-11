#include<bits/stdc++.h>
using namespace std;
int x[300010]={},a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,flag=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(x[a[i]]) flag=1;
		else x[a[i]]++;
	}
	if(flag==0){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[j]==i){
					cout<<j<<" ";
					break;
				}
			}
		}
	}
	else{
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++){
			vector<int> v1,v2(300050,0);
			for(int j=i;j<=n;j++){
				if(v2[a[j]]==0){
					x[a[j]]++,v2[a[j]]++;
					v1.push_back(a[j]);
				}
				else{
					int cnt=v1.size()-1;
					while(v1[cnt]!=a[j]){
						x[v1[cnt]]--,v2[v1[cnt]]--;
						v1.erase(v1.begin()+cnt);
						cnt--;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(i==1) cout<<x[i]; 
			else cout<<" "<<x[i];
		}
	}
	return 0;
} 
