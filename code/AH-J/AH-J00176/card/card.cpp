#include<bits/stdc++.h>
using namespace std;
char a[510000];
long long st[310000];
int main(){
	freopen("card.in","w",stdin);
	freopen("card.out","r",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	for(long long i=1;i<=n;i++){
		string sss="";
		int sz=sss.size();
		for(int j=i;j<=n;j++){
			int u=sss.find(a[j]);
			
			if(u!=0){
				for(int k=sz;k>=0;k--){
					if(sss[k]==a[j]){
						sz=k;
					}
				}sss[sz]=a[j];
				sz++;
			}else{
				sss+=a[j];
				sz++;
			}
		}for(int q=0;q<sz;q++){
			st[(int)sss[q]-48]++;
		}
	}for(int i=1;i<=m;i++){
		cout<<st[i]<<" ";
	}
	return 0;
}
