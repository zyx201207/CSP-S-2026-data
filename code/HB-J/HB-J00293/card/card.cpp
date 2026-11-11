#include <bits/stdc++.h>
using namespace std;
int n,m,a[200009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=0,A=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<=f) A=1;
	}
	if(A==0){
		for(int i=1;i<=m;i++){
			cout<<i<<' ';
		}
	}
	else if(m==2){
		int cnt=0,num=0;
	
		for(int i=1;i<=n;i++){
			for(int j=n;j>=i;j--){
				if(a[j]==1){
					cnt++;
					break;
				}
			}
		}
		cout<<cnt<<' '<<n-cnt;
	}
	return 0;
}
