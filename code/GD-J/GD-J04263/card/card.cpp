#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500001],dp[500001],pd[300001],ij,kkk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=1;k<=ij;k++){
				if(a[j]==dp[k]){
					ij=k-1;
					break;
				}
			}
			ij++;
			dp[ij]=a[j];
		}
		for(int j=1;j<=ij;j++)pd[dp[j]]++;
		kkk=0;
		ij=0;
	}
	for(int i=1;i<=m;i++)cout<<pd[i]<<" ";
	return 0;
}//天灵灵，地灵灵，给个一等行不行！
