#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],n,m,c[N],sum=0;
int b[N];
deque<int>q;
//struct node{
//	int l,r;
//}d[N];
//queue<
//bool cmp(node a1,node b1){
//	if(a1.l==b1.l){
//		return a1.r>b1.r;
//	}
//	return a1.l<b1.l;
//}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
//		if(c[a[i]]){
//			d[++sum]={c[a[i]],i};
//		}else c[a[i]]=i;
//		c[a[i]]=1-c[a[i]];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q.push_back(a[j]);
			if(b[a[j]]){
				int q1=q.size(),k=1;
				for(int ;k<=q1;k++){
					q.pop()_front();
					if(q.front()==a[j]){
						break;
					}
				}
				for(;k<=q1;k++){
					q.push_back(q.front());
					q.pop_front();
				}
			}
		}
		while(!q.empty()){
			b[q.front()]++;
				q.pop_front();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
