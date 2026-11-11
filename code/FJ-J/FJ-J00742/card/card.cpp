#include<bits/stdc++.h>
using namespace std;
long long card[500005],card_chu[500005]={0},sum[300005]={0};
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>card[200005];
	}
	long long sum=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			card_chu[j]=card[j];
			for(int k=i;k<j;k++){
				if(card_chu[j]==card_chu[k]){
					for(int l=k;l<j;l++){
						card_chu[l]=0;
					}
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			for(int k=i;k<=n;k++){
				if(card_chu[k]==j){
				    sum[j]++;
				    break;
			    }
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	return 0;
}
