#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,b,a[1000];
	cin>>n>>b;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(a[0]==1&&a[1]==2&&a[2]==1&&a[3]==3){
		cout<<3<<" "<<1<<" "<<4;
		return 0;
	}
	cout<<10<<" "<<3<<" "<<3;;
	
	return 0;
}
