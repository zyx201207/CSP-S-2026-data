#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,max=0;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if((a[i] & a[j])>max and a[i]!=a[j]){
					max=(a[i] & a[j]);
				}
			}
		}
	}
	else if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				for(int k=1;k<=j;k++){
					if((a[i] & a[j] & a[k])>max and a[i]!=a[j] and a[i]!=a[k] and a[j]!=a[k]){
						max=(a[i] & a[j] & a[k]);
					}
				}
			}
		}
	}
	else if(m==4){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				for(int k=1;k<=j;k++){
					for(int l=1;l<=k;l++){
						if((a[i] & a[j] & a[k] &a[l])>max and a[i]!=a[j] and a[i]!=a[k] and a[j]!=a[k] and a[i]!=a[l] and a[j]!=a[l] and a[k]!=a[l]){
							max=(a[i] & a[j] & a[k]  & a[l]);
						}
					}
				}
			}
		}
	}
	else{
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			max=a[n-1];
		}
	}
	cout<<max;
	return 0;
}