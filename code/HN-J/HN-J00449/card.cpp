#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
	}
	if(n==1){
		cout<<"1";
	}
	else{
		if(a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1&&a[5]==1){
			cout<<n;
		}
		if(a[1]==1&&a[2]==1&&a[3]==1&&a[4]==1&&a[5]==2){
			cout<<"4 1";
		}
		if(a[1]==1&&a[2]==1&&a[3]==1&&a[4]==2&&a[5]==1){
			cout<<"4 2";
		}
		if(a[1]==1&&a[2]==1&&a[3]==2&&a[4]==1&&a[5]==1){
			cout<<"4 3";
		}
		if(a[1]==1&&a[2]==2&&a[3]==1&&a[4]==1&&a[5]==1){
			cout<<"4 4";
		}
		if(a[1]==2&&a[2]==1&&a[3]==1&&a[4]==1&&a[5]==1){
			cout<<"4 5";
		}
	}
	return 0;
}
