//GZ-J00017 贵阳市白云区华师一学校 闫宇凡 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],s[300005];
map<int,bool> b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	bool d1=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]<a[i-1]){
			d1=0;
		}
	}
	if(d1==1&&n>5000){
		for(int i=1;i<=m;i++){
			printf("%d ",i);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		b.clear();
		queue<int> q;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				q.push(a[j]);
				b[a[j]]=1;
			}
			else{
				queue<int> q1;
				while(!q.empty()){
					int t=q.front();
					q.pop();
					if(t==a[j]){
						break;
					}
					else{
						q1.push(t);
					}
				}
				b[a[j]]=1;
				q1.push(a[j]);
				q=q1;
			}
		}
		while(!q.empty()){
			s[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s[i]);
	}
	return 0;
}
