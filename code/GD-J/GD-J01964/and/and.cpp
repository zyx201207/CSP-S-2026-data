#include<bits/stdc++.h>
using namespace std;
int a[2000005][35],l,ans[35],q[200005];
long long n,m,as;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		long long x;
		scanf("%lld",&x);
		int q=0;
		while(x>0){
			a[i][q]=x%2;
			x>>=1;
			q++;
		}
		l=max(l,q);
	}
	for(int i=l-1;i>=0;i--){
		int r=0;
		for(int j=0;j<n;j++){
			if(a[j][i]==1){
				q[r]=j;
				r++;
			}
			if(r==m){
				break;
			}
		}
		if(r==m){
			break;
		}
	}
	for(int j=0;j<=l-1;j++){
		bool o=true;
		for(int i=0;i<m;i++){
		    if(a[q[i]][j]==0){
		    	o=false;
		    	break;
			}
	    }
	    if(o==true){
	    	ans[j]=1;
		}
	}
	long long p=1;
	for(int i=0;i<35;i++){
		if(ans[i]==1){
			as+=p;
		}
		p*=2;
	}
	printf("%lld",as);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
