#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	long long a[n+15],b[n+15],cnt=1,c[n+15];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=0;
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=cnt;k++){
			b[cnt]=a[i];
			cnt++;
			if(b[k]==b[cnt]){
				for(int j=i+1;j<=cnt;j++){
					b[j]=0;
				}
				break;
			}
		}
		for(int j=1;j<=cnt;j++){
			for(int k=1;k<=n;k++){
				if(a[k]==b[j]){
					c[k]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<c[i]<<endl;
	}
} 
