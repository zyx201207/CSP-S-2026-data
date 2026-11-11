#include<bits/stdc++.h>
using namespace std;
int n,m,c;
int a[300005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(a[i]==b[i]){
		c++;	
		}
	}
	if(c==n){
		for(int i=1;i<=m;i++){
			cout<<n<<" ";
		}
	}
	return 0;
}
