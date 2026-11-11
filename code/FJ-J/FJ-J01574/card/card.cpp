#include<bits/stdc++.h>
using namespace std;
int a[10001];
int s[10001];
int vis[10001];
int k[10001];

int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
		s[i]=vis[a[i]];
	
	}
	for(int i=1;i<=n;i++){
		if(i!=1){
			vis[a[i-1]]--;
			if(vis[a[i-1]]!=0)
			for(int j=i;j<=n;j++)
				if(a[j]==a[i-1])s[j]--;
		}
//		bool p[10001]={0};
		for(int j=i;j<=n;j++){
			if(s[j]==vis[a[j]])
				for(int p=j;p<=n;p++)k[a[p]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<k[i]<< ' '<<'\n';
	
	return 0;
}//4 3 1 2 1 3

