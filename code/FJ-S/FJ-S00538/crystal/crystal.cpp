#include<bits/stdc++.h>
using namespace std;
long long a[500001],m,n,ans;
bool b1,b2;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)b1=1;
	}
	long long f=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=f)b2=1;
	}
	if(!b1){
		long long tmp=1,sum=1;
		while(n>0){
			n-=tmp;
			sum++;
			tmp++;
		}
	}else if(!b2){
		long long tmp=f,sum=1;
		while(n>0){
			n-=tmp;
			sum++;
			tmp+=f;
		}
	}else{
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i++){
			long long tmp=0,sum=1;
			for(int j=i-1;j>=1;j--){
				tmp+=a[i]-a[j];
				if(tmp<=m){
					sum++;
				}else{
					break;
				}
			}
			if(sum>ans){
				ans=sum;
			}
		}
		cout<<ans;
	}
	return 0;
}
