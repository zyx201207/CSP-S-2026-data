#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],vis[N],cnt[N],n,m; 
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof(vis));
		for(int j=i;j<=n;j++){
			if(!vis[a[j]]){
				s.push(a[j]);
				vis[a[j]]=1;
			}
			else{
				while(s.top()!=a[j]){
					vis[s.top()]=0;
					s.pop();
				}	
			}
		} 
//		printf("\nµÚ%d´Î:",i);
		while(!s.empty()){
			cnt[s.top()]++;
//			cout<<s.top()<<" ";
			s.pop();
		}
	}
//	cout<<"\n";
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]); 
	}
	return 0;
}

