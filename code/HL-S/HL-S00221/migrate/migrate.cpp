#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int y=1;y<=t;y++){
		int n,d,a[N],cnt=0;
		cin>>n>>d;
		for(int s=1;s<=n;s++){
			cin>>a[s];
		}
		for(int i=1;i<=n;i++){
			int k[N];
			for(int j=i;j<=n;j++){
				k[i]=0;
				if(a[j]-a[i]<=d){
					k[j]=k[j-1]+1;
				}
				else{
					for(int p=j-i-d;p<=j;p++){
						k[j]+=k[p];
					}
				}
			}
			for(int l=i;l<=n;l++){
				if(k[l]==2){
					cnt++;
				}
			}	
		}cout<<cnt;
	}
	return 0;
}
