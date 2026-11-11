#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1]={};
	int b[n+1]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int c[m+1]={};
	for(int i=1;i<=n;i++){
		for(int j=n;j>=i;j--){
			c[a[j]]++;
			if(b[a[j]]>1)
				break;
		}
		b[a[i]]--;
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
    return 0;
}
