#include<bits/stdc++.h>
using namespace std;
long long n,m,k;
long long a[10000000],ans[10000000],ordered[10000000];
void zero(int A){
	int B=0;
	for(int i=A;i<=k;i++){
		ordered[i]=0;
		B++;
	}
	k-=B;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		zero(0);
		int k=0;		
		for(int j=i;j<=n;j++){
			int r=0;
			for(int i=0;i<=k;i++){
				if(ordered[i]==a[j]){
					r=i;
				}
			}
			if(r!=0){
				int B=0;
				for(int i=r;i<=k;i++){
					ordered[i]=0;
					B++;
				}
				k-=B;
			}
			k++;
			ordered[k]=a[j];			
		}
		for(int j=1;j<=k;j++){
			ans[ordered[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";	
	}
	return 0;
} 
