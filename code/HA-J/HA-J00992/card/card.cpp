#include<bits/stdc++.h>
using namespace std;
int n,m;
int tong[300005];
int a[500005],f[500005];
int y=1;
queue<int> q;
int d[500005];
int idx=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		memset(d,0,sizeof(d));
		if(!tong[a[i]]){  
			q.push(a[i]);
			while(!q.empty()){
				d[++idx]=q.front();
				f[q.front()]++;
				q.pop();
			}
			for(int k=1;k<=idx;k++){
				q.push(d[k]);
			}
			tong[a[i]]++;
		}
		else{
			q.push(a[i]);
			while(!q.empty()){
				d[++idx]=q.front();
				q.pop();
			}
			for(int k=1;k<=idx;k++){
				q.push(d[idx-k+1]);
			}
			idx=0;
			memset(d,0,sizeof(d));
			while(q.front()!=a[i]||y<2){
				if(q.front()==a[i]) y++;
				tong[q.front()]--;
			//	cout<<q.front()<<" ";
				q.pop();
			}
			y=1;idx=0;
			while(!q.empty()){
				d[++idx]=q.front();
				f[q.front()]++;
				q.pop();
			}
			for(int k=1;k<=idx;k++){
				q.push(d[idx-k+1]);
			}
		}
		idx=0;
	}
	for(int i=1;i<=m;i++){
		cout<<f[i]<<" ";
	}
	return 0;
}

