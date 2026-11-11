#include<bits/stdc++.h>
using namespace std;
long long A[100000],C[100000],ans[100000],n,m,t;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool B[m+1]={0};
	for(long long i=1;i<=n;i++){
		cin>>A[i];
	}for(long long i=1;i<=n;i++){
		t=0;
		for(long long j=i;j<=n;i++){  
			if(B[A[j]]){
				for(long long l=t;l>=1;l--){
					if(C[l]==A[j])break;
					B[C[l]]=0;
					C[l]=0;
					t--;
				}
			}else {
				B[A[j]]=1;
				C[++t]=A[j];
			}
		}for(long long j=1;j<=t;j++){
			ans[C[j]]++;
			C[j]=0;
		}
	}for(long long i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
