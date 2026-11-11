#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[300005];
int main(){
	
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	for(int i=1;i<=m;i++){
		b[i]=i;
	}
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<n<<" ";
	}
	cout<<endl;
	return 0;
}
