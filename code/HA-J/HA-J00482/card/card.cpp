#include<bits/stdc++.h>
using namespace std;
int n,m;
int t[500005];
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	cout<<n<<" "<<m<<" "<<a[1]<<" ";
	if(m>3){
		for(int i=1;i<=m-3;i++){
			cout<<a[i]<<" ";
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<i;j++){
////			if(a[i]==a[j])
//		}
//	}
//	for(int i=1;i<=n;i++){
//		cout<<t[i];
//	}
	return 0;
}

