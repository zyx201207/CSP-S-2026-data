#include<bits/stdc++.h>
using namespace std;
int n,m,arr[200005],ejz[200005][35],ch[200005],tj[35];
long long ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",arr+i);
		int c=arr[i],p=0;
		while(c){
			ejz[i][p]=c%2;
			if(c%2){
				tj[p]++;
			}
			c/=2;
			p++;
		}
	}
	for(int i=30;i>=0;i--){
		if(tj[i]>=m){
			ans+=pow(2,i);
			for(int j=1;j<=n;j++){
				if(!ch[j]){
					if(!ejz[j][i]){
						ch[j]=1;
						for(int k=0;k<=30;k++){
							tj[k]-=ejz[j][k];
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
