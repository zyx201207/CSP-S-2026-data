#include<bits/stdc++.h>
using namespace std;

long long cnt[3000010],n,m,t[5000010],a[5000010],b[5000010];
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	memset(b,-1,sizeof(b));
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			t[a[j]]++;
			if(t[a[j]]==2){
				for(int k=i;k<=j;k++){
					if(b[k]==a[j]){
						for(int q=k;q<=j;q++){
							b[q]=-1;
						}
						break;
					}
				}
			}
		}
		for(int k=1;k<=m;k++){
			for(int j=1;j<=300000;j++){
				if(b[j]==k){
					cnt[k]++;
				}
			}
		}
		memset(b,-1,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]+1<<" ";
	}

    return 0;
}
