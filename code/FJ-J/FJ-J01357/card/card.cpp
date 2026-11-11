#include<bits/stdc++.h>
using namespace std;
int n,m,h,r,t[300005],a[500005];
queue<int> q;
bool c=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			c=1;
			for(int k=q.size();k>0;k--){
				h=q.front();
				q.pop();
				if(a[j]==h) c=0;
				q.push(h);
			}
			if(c) q.push(a[i]);
			else{
				for(int k=q.size();k>j;k--){
					q.pop();
				}
			}
		}
		while(!q.empty()){
			h=q.front();
			q.pop();
			for(int j=0;j<n;j++){
				if(h==a[j]){
					t[a[j]]++;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
