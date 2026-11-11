#include<bits/stdc++.h>
using namespace std;
long long c,t,d[320],a[320],ans[320],mmax;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
for (int l=1;l<=t;l++){
	long long n,f;
	mmax=0;
	cin>>n>>f;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
		for (int k=1;k<=n;k++){
		for (int i=k;i<=n;i++){
			d[i]=1000000000000000000;
			ans[i]=0;
		}
		d[k]=0;
		ans[k]=1;
		for (int i=k;i<=n;i++){
			for (int j=i-1;j>=k;j--){
				if (a[i]-a[j]>f){
					break;
				}
				//cout<<d[i]<<" ";
				if (d[j]+1<d[i]){
					d[i]=d[j]+1;
					ans[i]=ans[j];
				}
				else{
					if (d[j]+1==d[i]){
						ans[i]+=ans[j];
					}
				}
			}
		}
	//	for (int i=k;i<=n;i++){
	//		cout<<d[i]<<" ";
	//	}
	//	cout<<endl;
		for (int i=1;i<=n;i++){
			if (ans[i]==2){
				mmax++;
			}
		}		
	}
	cout<<mmax<<endl;	
	}

	//for (int i=1;i<=n;i++){
	//	cout<<d[i]<<" ";
	//}
	return 0;
}
