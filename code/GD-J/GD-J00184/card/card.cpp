#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],z[300005],ls[500005],top,cnt[300005];
bool yz=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			yz=0;
		}
	}
	//if(yz){
		//cout<<m;
		//return 0;
	//}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(z[a[j]]){
				for(int q=z[a[j]]+1;q<=top;q++){
					z[ls[q]]=0;
				}
				top=z[a[j]];
			}
			else{
				ls[++top]=a[j];
				z[a[j]]=top;
			}
		}
		for(int j=1;j<=m;j++){
			if(z[j]){
				cnt[j]++;
			}
			z[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
