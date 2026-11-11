#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n-m+1;i>=1;i++){
		int b[32];
		for(int i=1;i<=30;i++){
			b[i]=0;
		}
		int k=a[i],j=0,cnt=0;
		while(k){
			j++;
			b[j]=k%2;
			k/=2;
		}
		for(int l=i-1;l<=n;l++){
			int ok=1,o=0;
			int g=a[j];
			while(g){
				o++;
				if(b[j]==1&&g%2==0){
					ok=0;
				}
				g/=2;
			}
			cnt+=ok;
		}
		if(cnt>=m){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}


