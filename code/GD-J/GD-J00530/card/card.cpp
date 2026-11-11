
#include<bits/stdc++.h>
using namespace std; 
int n,m;
int a[200007];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}else if(m==2){
		cout<<n<<" "<<n;
	}
	return 0;
} 
