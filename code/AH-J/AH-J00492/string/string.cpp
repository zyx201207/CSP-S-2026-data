#include<bits/stdc++.h>
using namespace std;
int N,A[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d%1s",&A[i],&c[i]);
	long long ans=0;
	int i=1,j=N;
	while(i<j){
		long long tmp=min(A[i],A[j]);
		if(c[i]!=c[j])
			ans+=tmp;
		int f=A[i];
		A[i]-=tmp;
		A[j]-=tmp;	
		if(tmp==f)
			i++;
		else j--;
	
	}
	printf("%lld",ans);
	return 0;
}
