#include<bits/stdc++.h>
using namespace std;
int n,m,p[300005],z[500005];
queue<int>a;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int q;
		cin>>q;
		a.push(q);
	}
	for(int i=1;i<=n;i++){
		int w=n;
		while(w>0){
			int cnt=1,zs=1;
			for(int j=1;j<=cnt;j++){
				if(z[j]==a.front()){
					for(int k=j+1;k<=cnt-1;k++){
						a.push(z[k]);
						z[k]=0;
						cnt-=1; 
					}
					a.pop();
					w-=1;
					zs=0;
				}
			}
			if(zs==1){
				z[cnt]=a.front();
				cnt+=1;
				a.pop();
				w-=1;
			}
		}
		for(int j=1;j<=n;j++)p[z[i]]+=1;
	}
	for(int i=1;i<=500005;i++){
		if(p[i]!=0)cout<<p[i];
	}
	return 0;
} 
