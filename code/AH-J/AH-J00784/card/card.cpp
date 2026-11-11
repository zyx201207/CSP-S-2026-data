#include<bits/stdc++.h>
using namespace std;
int a[200004], b[200001];
int ans1=0, ans2=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			b[j]==a[j];
			for(int k=j;k<=n;k++){
				if(k!=i){
					if(a[j]==a[k]){
						memset(b,0,sizeof(b));
					}
				}
			}
		}
		for(int j=1;j<=n;j++){
			if(b[j]==1)ans1++;
			else if(b[j]==2)ans2++;
		}
	}
	cout<<ans1<<" "<<ans2;
	return 0;
}

