#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[100000];
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		s=max(s,a[i]);
	}
	cout<<n<<" "<<m<<" "<<s;
	return 0;
} 
