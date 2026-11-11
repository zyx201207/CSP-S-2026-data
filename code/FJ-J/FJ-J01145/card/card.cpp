#include <bits/stdc++.h>
using namespace std;

int n,m,a[10001],b[10001],c[100001];
bool vv[10010];

int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;

	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}

		for(int i=1; i<=n; i++) {


			if(vv[a[i]]!=0) {

				for(int j=1; j<=n; j++) {
					b[j]=0;
					vv[b[j]]=0;
				}

			}
			b[i]=a[i];
			vv[b[i]]=1;
			
		}
		
		for(int i=1; i<=n+1; i++) c[b[i]]++;
	
	
	if(m>=2){
		for(int i=2; i<=n; i++) {


			if(vv[a[i]]!=0) {

				for(int j=1; j<=n; j++) {
					b[j]=0;
					vv[b[j]]=0;
				}

			}
			b[i]=a[i];
			vv[b[i]]=1;
			
		}
		
		for(int i=1; i<=n*2; i++) c[b[i]]++;
	}
	
	if(m>=3){
		for(int i=3; i<=n; i++) {


			if(vv[a[i]]!=0) {

				for(int j=1; j<=n; j++) {
					b[j]=0;
					vv[b[j]]=0;
				}

			}
			b[i]=a[i];
			vv[b[i]]=1;
			
		}
		
		for(int i=1; i<=n*2; i++) c[b[i]]++;
	}

	for(int i=0; i<=n; i++)  cout<<c[i]<<" ";
}

//感谢CCF提供的宝贵机会qwq

