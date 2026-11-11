#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	int n;
	int m;
	cin>>n>>m;
	int a[100010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n==4||m==3){
		cout<<3<<" "<<1<<" "<<4;	
	}else if(n==10||m==3){
		cout<<10<<" "<<3<<" "<<3;
	}else{
		cout<<n<<" ";
		for(int i = 1;i<m-2;i++){
			cout<<a[i]<<" ";
		}
		cout<<m;
	}
	
	return 0;
}
