#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m;
int G[N],l[N],r[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>G[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i-1;j++){
			l[j]=G[j];
		}
		for(int j=i;j<=n;j++){
			r[j]=G[j];
		}
		int num=n-i+1,cnt=1;
		while(num){
			for(int j=1;j<=i-1;j++){
				if(l[j]==r[cnt]){
					for(int k=j;k<=i-1;k++){
						l[k]=0;
					}
					l[i]=r[cnt];
					break;
				}
				else{
					l[i]=r[cnt];
					r[cnt]=0;
				}
			}
			num--;
		}
		if(l[i]==i){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
