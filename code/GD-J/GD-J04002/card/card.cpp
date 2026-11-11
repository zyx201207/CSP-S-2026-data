#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int n,m,a[N],ans[N],lst[N],h[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(h[a[i]])lst[i]=h[a[i]];
		h[a[i]]=i;
	//	cout<<lst[i]<<" ";
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++)d[j]=0; 
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			if(lst[j]){
				if(d[lst[j]])continue;
				if(lst[j]<i)continue;
				for(int k=lst[j];k<j;k++){
					if(d[k])continue;
					ans[a[k]]--;
					d[k]=1;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
