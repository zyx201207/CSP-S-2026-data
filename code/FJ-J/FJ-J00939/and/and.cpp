#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int maxx=INT_MIN;
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	if(m==2){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				maxx=max(maxx,(a[i]&a[j]));
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			maxx=max(maxx,a[i]);
		}
		cout<<maxx;
		return 0;
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				for(int k=1;k<=n;k++){
					if(i==k)continue;
					if(k==j)continue;
					maxx=max(maxx,((a[i]&a[j])&a[k]));
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	return 0;
}
