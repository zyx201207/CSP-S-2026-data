#include<bits/stdc++.h>
using namespace std;
int n,m,y,x;
int a[500005],num[500005],k[500005];
void dfs(int t,int sum,int p){
	if(p>n-t+1){
		return;
	}
	for(int i=1;i<=sum;i++){
		if(num[i]==a[p]){
			y=a[p];
			x=p-i;
			return;
		}
	}
	sum+=1;
	num[sum]=a[p];
	dfs(t,sum,p+1);
	sum-=1;
	if(num[sum]==y){
		y=0,x=0;
		dfs(t,sum,p+x+1);
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool f=true;
	for(int i=1;i<n;i++){
		if(a[i]>a[i+1]){
			f=false;
		}
	}
	if(f==true){
		for(int i=1;i<=m;i++){
			cout<<1<<" ";
		}
	}
	else{
		for(int i=1;i<=n;i++){
			dfs(i,0,1);
			for(int j=1;;j++){
				if(num[j]==0){
					break;
				}
				k[num[j]]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<k[i]<<" ";
		}
	}

	return 0;
}

