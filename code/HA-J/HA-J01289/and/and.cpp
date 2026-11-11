#include<bits/stdc++.h>
using namespace std;
int ans,a[200005],n,m,tmp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//Æ­·ÖÕâÒ»¿é 
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]);
		}
	}
	if(m==2){
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	if(m==n){
		ans=a[0];
		for(int i=1;i<n;i++){
			ans=ans&a[i];
		}
	}
	if(m==n-1){
		for(int i=0;i<n;i++){
			if(i!=0)tmp=a[0];
			else tmp=a[1];
			for(int j=1;j<n;j++){
				if(i==0&&j==1)continue;
				if(i==j)continue;
				tmp=tmp&a[j];
			}
			ans=max(ans,tmp);
		}
	}
	printf("%d",ans);
	return 0;
}
