#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
queue<int> q;
int n,m,a[N],w[N],ans[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int cnt=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)w[i]=0;
		for(int j=i;j<=n;j++){
			if(a[i]==w[i-1])continue;
			else w[cnt]=a[i],cnt++;
		}
		for(int j=1;j<=cnt;j++){
			ans[w[i]]++;
			cout<<w[i];	
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" "; 
	}
	return 0;
}
/*
4 3
1 2 1 3

3 3
1 3 3
1 3
3
3
*/
