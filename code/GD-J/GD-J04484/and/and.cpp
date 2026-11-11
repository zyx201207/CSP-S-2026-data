#include <bits/stdc++.h>
using namespace std;

const int N=2e5+9; 
int a[N+5],maxn=0;
int n,m;

void find(int l,int num,int pos){
	if(l==0){
		maxn=max(maxn,num);
		return;
	} 
	for(int i=pos+1;i<=n;i++){
		int k = num&a[i],p=l-1;
		find(p,k,i);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<=n;i++){

		find(m-1,a[i],i);
	}
	cout << maxn;
}
