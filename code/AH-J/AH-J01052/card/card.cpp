#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],cnt[200005],x;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];	
	}
	int t=0;
	while(t!=n){
		unordered_map<int,int> c;
		for(int i=1;i<=m;i++){
			c[m]=-1;
		}
		for(int i=n-t;i<n;i++){
			if(c.count(a[i])!=1){
				c[a[i]]=x;
				x++;
			}else{
				int t=c.at(a[i]);
				for(int i=1;i<=m;i++){
					if(c[m]<=t&&c[m]!=-1){
						x=min(x,c[m]);
						c[m]=-1;
					}
				}
				c[a[i]]=x;
				x++;
			}
		}
		for(int i=n-t;i<n;i++){
			if(c.count(a[i])){
				if(c.at(a[i])!=-1){
					cnt[i]++;
				}
			}	
		}
		t++;
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

