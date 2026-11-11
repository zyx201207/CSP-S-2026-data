#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("card.in","r",stdin);
//	freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int cnt[n+5]={0};
    int a[n+5];
    int a_1[n];
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	if(n<=5000&&m<=3000){
    	for(int i=1;i<=m;i++){
    		cout<<n<<" ";
			}
	}
	for(int x=1;x<=m;x++){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				for(int k=1;k<=i;k++){
					a_1[k]=' ';
					a_1[k]=j;
				}
			}
		}
	}
}
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=m;j++){
    	if(a_1[i]==j){
    		cnt[j]++;
		}
	}
	}	
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
