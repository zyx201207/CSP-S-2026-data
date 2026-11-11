#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt=1,b[500005],ans[300005];
queue<int>q;
int main(){
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!q.size()){
				q.push(a[j]);
				b[cnt]=a[j];
				cnt++;
			}else{
				bool f=0;
				for(int p=1;p<=cnt;p++){
					if(b[p]==a[j]){
						f=1;
						b[p]=-1;
					}
				}
				q.push(a[j]);
				b[cnt]=a[j];
				cnt++;
				if(f){
					while(q.front()==a[j]){
						q.pop();
					}
					q.pop();
				}
			}
		}
		while(q.size()){
			ans[q.front()]++;
			q.pop();
		}
		b[cnt]=0;
		while(cnt--){
			b[cnt]=0;
		}
		cnt=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
