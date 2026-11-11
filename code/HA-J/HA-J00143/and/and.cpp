#include<bits/stdc++.h> 
using namespace std;

int n,m;
long long a[200005];
int k(int x,int y){
	return x&y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<maxn<<endl;
			maxn=max(maxn,k(a[i],a[j]));
		}
	}
	cout<<maxn;
	return 0;
}
