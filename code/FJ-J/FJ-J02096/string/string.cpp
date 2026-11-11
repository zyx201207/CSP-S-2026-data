#include<bits/stdc++.h>
using namespace std;
long long sum,ans,a[200005];
char b[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		ans+=a[i];
	}
	for(long long i=1,j=ans,k=1,v=n;i<j;){
		if(b[k]==b[v]){
			if(a[k]>a[v]){
				i+=a[v];
			    j-=a[v];
			    a[k]-=a[v];
			    v--;
			}else if(a[k]==a[v]){
				i+=a[k];
				j-=a[v];
				a[k]=0;
				a[v]=0;
				k++;
				v--;
			}else{
				i+=a[k];
				j-=a[k];
				a[v]-=a[k];
				k++;
			}
		}else{
			sum+=min(a[k],a[v]);
			if(a[k]>a[v]){
				i+=a[v];
			    j-=a[v];
			    a[k]-=a[v];
			    v--;
			}else if(a[k]==a[v]){
				i+=a[k];
				j-=a[v];
				a[k]=0;
				a[v]=0;
				k++;
				v--;
			}else{
				i+=a[k];
				j-=a[k];
				a[v]-=a[k];
				k++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
