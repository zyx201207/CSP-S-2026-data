#include <bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<1;
	}
	else if(m==2){
		int cnt=0;
		for(int i=1;i<=2;i++){
			if(a[i]==i)cnt++;
		}
		cout<<cnt;
	}
	else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}
		cout<<cnt;
	}

	return 0;
}

