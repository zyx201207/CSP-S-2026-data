#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],vis[300005];
queue <int> q,q2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
//	for(int i=1;i<=n;i++){
//		memset(vis,0,sizeof(vis));
//		for(int j=i;j<=n;j++){
//			if(vis[a[j]]==0){
//				vis[a[j]]=1;
//				if(q2.size()==0){
//					q.push(a[j]);
//				} 
//				else{
//					q2.push(a[j]);
//				} 
//			}
//			else{
//				
//				if(q2.size()==0){
//					for(int k=1;k<=n;k++){
//						q2.push(q.front());
//						q.pop();
//						if(q.front()==a[j]){
//							q2.push(q.front());
//							while(q.size()>0) q.pop();
//							break;
//						}
//					}
//				}
//				else{
//					for(int k=1;j<=n;k++){
//						q.push(q2.front());
//						q2.pop();
//						if(q2.front()==a[j]){
//							q.push(q2.front());
//							while(q2.size()>0) q2.pop();
//							break;
//						}
//					}
//				}
//				
//			}
//			
//		}
//		while(q.size()){
//			ans[q.front()]++;
//			q.pop();
//		}
//		while(q2.size()>0){
//			ans[q2.front()]++;
//			q2.pop();
//		}
//	}
//	for(int i=1;i<=m;i++){
//		cout<<ans[i]<<' ';
//	}
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<n-2<<' ';
	}
	return 0;
}
