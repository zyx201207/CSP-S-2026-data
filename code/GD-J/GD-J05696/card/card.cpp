#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N],cnt[M];
int q[N];
int ed=1;
bool check(int x){
	for(int i=1;i<ed;i++){
		if(x==a[i])return 0;
	}
	return 1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(a[j])){
				 q[ed++]=a[j];
			}else{
				int u;
				for(int k=1;k<ed;k++){
					if(q[k]==a[j])u=k;
				}
				ed=u;
				q[ed++]=a[j];
			}
		}
		for(int k=1;k<ed;k++){
			cnt[q[k]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
