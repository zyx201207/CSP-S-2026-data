#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
long long n,m,a[500005],b[300005],c[500005],x,cnt=1;
queue<int> q;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>500&&m>200){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				b[a[j]]++;
			}
		}	
	}
	else{
		for(int i=1;i<=n;i++){
			cnt=1;
			for(int j=i;j<=n;j++){
				q.push(a[j]);
			}
			while(q.empty()==0){
				x=q.front();
				q.pop();
				for(int j=1;j<=cnt;j++){
					if(c[j]==x){
						cnt=j+1;
						break;
					}
					if(j==cnt){
						c[cnt]=x;
						cnt++;
						break;
					}
				}
			}
			for(int j=1;j<cnt;j++){
				b[c[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
} 
