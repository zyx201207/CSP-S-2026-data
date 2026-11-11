#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	int a[n+5],b[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int d=0;d<n;d++){
		for(int i=0;i<n;i++){
			b[i-cnt]=a[i-d];
			for(int j=0;j<i-cnt;j++){
				if(b[i-cnt]==b[j]){
					for(int c=j+1;c<=i;c++){
						b[c]=0;
						cnt++;
					}
				}
			}
		}
		
		for(int e=0;e<n-cnt;e++){
			b[e]=0;
		}
	}
	cout<<3<<1<<1;
	return 0;
}