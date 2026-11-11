#include<bits/stdc++.h>
using namespace std;
int a[2010],n,m,MAX=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=i;j++){
			if(a[i]&a[j]>MAX)MAX=a[i]&a[j];
		}
	}
	cout<<MAX;
	return 0;
}
