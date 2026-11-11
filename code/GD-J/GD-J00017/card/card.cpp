#include<bits/stdc++.h>
using namespace std;
int a[500005],n,m,cnt[300005],x[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		stack<int>b;
		for(int j=1;j<=300000;j++){
			x[j]=0;
		}
		for(int j=1;j<i;j++){
			b.push(a[j]);
		}
		for(int j=i;j<=n;j++){
			int x=0,si=0;
			for(int k=1;k<j;k++){
				if(a[k]==a[j]){
					if(x==0){
						si=k;
					}
					x++;
				}
			}
			if(x>=1){
				for(int l=1;l<=j-si;l++){
					b.pop();
				}
			}
			b.push(a[j]);
		}
		while(!b.empty()){
			if(x[b.top()]==0){
				cnt[b.top()]++;
			}
			x[b.top()]++;
			b.pop();
		}
	}
	for(int i=1;i<=300000;i++){
		if(cnt[i]>=1){
			cout<<cnt[i]<<" ";
		}
	}
	return 0;
}
