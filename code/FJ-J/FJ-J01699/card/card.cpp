#include<bits/stdc++.h>
using namespace std;
int n,m,a[10]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		cout<<n;
	}
	if(m==2){
		int cnt1=0,cnt2=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			if(a[i]==1) cnt1++;
			else cnt2++;
		}
		cout<<cnt1<<' '<<cnt2;
	}
	return 0;
} 
