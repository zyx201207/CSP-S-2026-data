#include<bits/stdc++.h>
using namespace std;
int inn[300005],cnt[300005],sh[500005]; 

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); 
	int n,m,flag=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>sh[i];
		if(sh[i]<sh[i-1]){
			flag=0;
		}
	}
	if(flag){
		for(int i=1;i<=n;i++){
			cnt[sh[i]]=max(cnt[sh[i]],i);
		}
		for(int i=1;i<=m;i++){
			cout<<cnt[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> s;
		memset(inn,0,sizeof(inn));
		for(int j=i;j<=n;j++){
			if(inn[sh[j]]==0){
				s.push(sh[j]);
				inn[sh[j]]=1;
			}else{
				while(!s.empty()&&s.top()!=sh[j]){
					inn[s.top()]=0;
					s.pop();
				}
			}	
			
		}
		for(int j=1;j<=m;j++){
			if(inn[j]){
				cnt[j]++;
			}
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
