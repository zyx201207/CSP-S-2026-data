#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<=n;i++){
		while(a[i]>0){
			long long m=a[j];
			a[j]-=a[i];
			if(c[i]!=c[j])ans+=m-max(0ll,a[j]);
			if(a[j]<=0)a[i]=-a[j];
			else a[i]=0;
			if(a[j]<=0){
				a[j]=0;
				j--;
			}
			if(j==i||a[i]==0)break;
		}
		if(j==i){
			break;
		}
	}
	cout<<ans;
	return 0;
} 


