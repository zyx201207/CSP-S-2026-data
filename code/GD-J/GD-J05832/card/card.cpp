#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int m;
int a[1000001];
int b[1000001];
int num[1000001];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		for(int j=1;j<=n;j++){
			if(b[j]==1){
				num[1]++;
			}if(b[j]==2){
				num[2]++;
			}if(b[j]==3){
				num[3]++;
			}if(b[j]==b[i]){
				for(int k=j;k<=i;k++){
					b[k]=0;
				}
			}
			}
		}for(int i=1;i<=3;i++){
			cout<<num[i];
		}
		return 0;	
}
