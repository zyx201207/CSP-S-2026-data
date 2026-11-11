#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int a[N],e[M],l[N],n,m,cnt[M],q[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];  
		l[i]=e[a[i]];
		e[a[i]]=i;
	}

	for(int i=n;i>=1;i--){
		q[l[i]]=i;
	}

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;){
			if(q[j]!=0){
				j=q[j];
			}
			else{
				cnt[a[j]]++;
				j++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
