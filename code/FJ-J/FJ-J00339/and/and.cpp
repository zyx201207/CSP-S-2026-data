#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans=(1<<30)-1,ok[30];
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=29;i>=0;i--){
		if(m==0) break;
		for(int j=1;j<=n;j++){
			if((a[j]&1<<i)==(1<<i)){
				ok[i]++;
				if(ok[i]==2){
					ans=ans&a[j];a[j]=0;
					m--;
				    break;
				}
			}
		}             
	}
	cout<<ans;
	return 0;		
}