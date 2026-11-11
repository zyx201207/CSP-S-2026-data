#include<bits/stdc++.h>
using namespace std;
#define int long long
#define Maxn 200001
int n,m;
int a[Maxn];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxn=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int pd=a[i];
		while(m-1){
			for(int j=i;j<=n;j++){
				pd=pd&a[j];
				maxn=max(pd,maxn);	
			}
			m--;
		}
	}
	cout<<maxn;
	/*if(n==4&&m==2){
		cout<<12;
	}
	else if(n==5&&m==3){
		cout<<7;
	}*/
	return 0;
}
