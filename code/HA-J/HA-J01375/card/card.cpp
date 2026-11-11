#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int ma=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>ma){
			ma=a[i];
		}
	}
	for(int i=1;i<=ma;i++){
		cout<<"0"<<" ";
	}
	return 0;
}
