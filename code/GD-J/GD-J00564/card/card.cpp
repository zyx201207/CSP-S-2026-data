#include<bits/stdc++.h>
using namespace std;
long long table[100000],sum[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[n+5]={};
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int table[100000]={};
		for(int j=i;j<=n;j++){
			int s=0,l=0;
			for(int x=1;x<=n;x++){
				if(a[j]!=table[x]){
					s=1;
				}
				else{
					s=0;
					l=x;
					break;
				}
			}
			if(s){
				table[j]=a[j];
			}
			else{
				for(int x=l;x<=n;x++){
					table[x]=0;
				}
				table[l]=a[j];
			}
		}
		for(int x=1;x<=n;x++){
			sum[table[x]]++;
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
