//GZ-J00500 遵义市第十二中学 梅东耀 
#include<bits/stdc++.h>
using namespace std;
long long a[500004],b[300004],c[300004],d[500004];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		queue<int>q;
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				q.push(a[j]);
				b[a[j]]=1;
			}else{
				int ix=0;
				while(1){
					if(q.front()==a[j]){
						while(q.size()){
							b[q.front()]=0;
							q.pop();
						} 
						for(int i=0;i<ix;i++) q.push(d[i]);
						memset(d,0,sizeof(d));
						break;
					}
					else{
						d[ix++]=q.front();
						q.pop();
					}
				}
				q.push(a[j]);
				b[a[j]]=1;
			}
		}
		while(q.size()){
			c[q.front()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}
