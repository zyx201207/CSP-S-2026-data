#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,p=3e5+10;
int n,m;
int a[N];
int b[p];
int h[p]; 
int pos;
void d(int x){
	int j=x,k=n;
		while(j<k){
			if(a[j]==a[k]){
				j=k;
				k=n;
			}
			else{
				k--;
			}
		}
		pos=j;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));	
		pos=i;		int maxn=0,minn=1e8;
		while(pos<=n){
		d(pos); 
		b[a[pos]]=1;
		maxn=max(a[pos],maxn);
		minn=min(a[pos],minn);
		pos++;
	}
		for(int l=minn;l<=maxn;l++){
			if(b[l]==1){
				h[l]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<h[i]<<" ";
	}
}
