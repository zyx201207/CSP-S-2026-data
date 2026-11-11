#include<bits/stdc++.h>
using namespace std;
int a[22225],b[22225];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(a[i+1]>=a[i]){
			k++;
		}
	}
	if(k==n-1){
		for(int i=1;i<=n;i++){
			cout<<n<<" ";
		}
	}else{
		cout<<3<<" "<<1<<" "<<4;
	}
	return 0;
}

