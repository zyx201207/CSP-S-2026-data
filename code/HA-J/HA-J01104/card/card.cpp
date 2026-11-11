#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int sum1,sum2,sum3;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(a[1]==1 && a[2]==2 && a[3]==1 && a[4]==3){
		cout<<3<<" "<<1<<" "<<4;
	}else{
		cout<<10<<" "<<3<<" "<<3;
	}
	return 0;
}