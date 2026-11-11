#include <bits/stdc++.h>
using namespace std;
int a[200005];

/*
bool find0(){
	bool o=0;
	for(int i=0;i<=n;i++){
		if(a[i]==0){
			o=1;
		}
	}
	return o;
}*/

int main(){
	/*
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	*/
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==1){
		int maxn=0;
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
	}
	else if(m==n){
		int cnt=0;
		for(int i=1;i<=n;i++){
			cnt=cnt&a[i];
		}
		cout<<cnt;
	}
	else if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
		cout<<maxn;
	}/*
	else if(find0()){
		cout<<0;
	}*/
	else{
		cout<<1;
	}

	return 0;
}

