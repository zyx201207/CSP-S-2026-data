#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	for(int i=0;i<n;i++){
		int a1[500005]={};
		for(int j=0;j<n;j++)a[j]=b[j];
		for(int j=0;j<n;j++){
			a1[j]=abs(a[j]-a[i]);
			
		}
		for(int k=0;k<n;k++){
			for(int l=0;l<n;l++){
				if(a1[k]<a1[l]){
					int t=a1[k];
					a1[k]=a1[l];
					a1[l]=t;
					t=a[k];
					a[k]=a[l];
					a[l]=t;
				}
			}
		}
		long long v=m,c=0,b=0;
		while(v&&c<n){
			if(v>=a1[c]){
				v-=a1[c];
				b++;
			}
			else{
				break;
			}
			c++;
		}
		ans=max(ans,b);
	}
	cout<<ans;
	return 0;
}

