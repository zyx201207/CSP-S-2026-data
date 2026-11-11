#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n,m,a[1000001],b[1000001],t[1000001],dis[1000001];
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) t[j]=0;
			for(int j=i;j<=n;j++){
				int s1=0;
				for(int z=i;z<j;z++){
					if(t[z]==0&&a[z]==a[j]){
						s1=z;
						break;
					}
				}
				if(s1!=0){
					for(int z=s1;z<j;z++) t[z]=1;
				}
			} 
			for(int j=i;j<=n;j++){
				if(t[j]==0) dis[a[j]]++;
	//			cout<<t[j];
			}
	//		cout<<"\n";
		}
		for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			dis[a[n]]++;
			if(a[i]!=a[n]) dis[a[i]]++;
		}
		for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
	}
	else{
		for(int i=1;i<=n;i++){
			t[a[i]]++;
		}
		for(int i=1;i<=n;i++){
			t[a[i]]--;
			if(t[a[i]]==0){
				dis[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++) cout<<dis[i]<<" ";
	}
	return 0;
}
