#include<bits/stdc++.h>
#include<queue>
using namespace std;
int n,m,a[1000000],d[1000000];
queue<int> b,c;
bool f[1000000],ff;
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int q=1;q<=n;q++){
		for(int i=q;i<=n;i++){
			if(!f[a[i]]){
				b.push(a[i]);
				f[a[i]]=1;
			}
			else{
				for(int j=1;j<=m;j++){
					f[j]=0;
				}
				int len=b.size();
				ff=0;
				for(int j=1;j<=len;j++){
					if(b.front()!=a[i]&&!ff){
						c.push(b.front());
						f[b.front()]=1;
						b.pop();
						continue;
					}
					if(b.front()==a[i]){
						c.push(b.front());
						b.pop();
						ff=1;
						continue;
					}
					
					b.pop();
				}
				for(int j=1;j<=c.size();j++){
					b.push(c.front());
					c.pop();	
				}
			}
		}
		int len=b.size();
		for(int i=1;i<=len;i++){
			d[b.front()]++;
			b.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<' ';
	}
	return 0;
}
