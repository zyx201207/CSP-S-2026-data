#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],mx[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for(int i=1;i<=n;i++){
		cin>>a[i]
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]>mx[j])mx[j]=a[i];
		}
	}
	if(m>1){
		for(int i=2;i<=m;I++){
			mx[i]=mx[i-1]&mx[i];
		}
		cout<<mx[m];
	}
	if(m==1)cout<<mx[m];
	if(m==0)cout<<0;
	return 0;
}



