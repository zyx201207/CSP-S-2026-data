#include<bits/stdc++.h>
using namespace std;

int num[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	int ans=0;
	scanf("%d%d",&n,&m); 
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	if(m==1){
		ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,num[i]);
		}	
	}else if(m==2){
		ans=0;
		for(int i=0;i<n;i++){
			for(int u=i+1;u<n;u++){
				ans=max(ans,num[i]&num[u]);
			}
		}	
	}else if(m==n){
		ans=num[0];
		for(int i=1;i<n;i++){
			ans=ans&num[i];
		}
	}else{
		ans=num[n-1];
		sort(num,num+n);
		for(int i=n-2;i>n-1-m;i--){
			ans=ans&num[i];
		}
	} 
	
	printf("%d",ans);
	return 0;
} 
