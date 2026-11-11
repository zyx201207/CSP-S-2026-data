#include<bits/stdc++.h>
using namespace std;
int a[2010],Maxn=0,sum=0,n,m,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		Maxn=max(Maxn,a[i]);
		if(i==1)
			ans=a[1];
		else
			ans=ans&a[i];
	}
	if(m==1){
		cout<<Maxn;
		return 0;
	}
	else if(m==n){
		cout<<ans;
		return 0;
	}
	else if(m==2){
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				sum=max(sum,a[i]&a[j]);
			}
		}
		cout<<sum<<endl;
		return 0;
	}
	else
		cout<<4;
	return 0;
}
