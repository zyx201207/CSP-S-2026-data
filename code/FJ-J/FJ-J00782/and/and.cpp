#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
int an(int a,int b){
	int r=0,sum=1;
	while(a>1&&b>1){
		if(a%2==b%2){
			r=r+sum;	
		}
		a=a/2;
        b=b/2;
		sum=sum*2;
	}
	if(a%2==b%2){
			r=r+sum;	
		}
		a=a/2;
        b=b/2;
		sum=sum*2;
	return r;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int num;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==2){
		ans=0;
    for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,an(a[i],a[j]));
		}
	}
	}else if(m==3){
		ans=0
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				ans=max(ans,an(a[k],an(a[i],a[j])));
			}
			
		}
	}	
	}else{
		for(int i=1;i<=n;i++){
			ans=min(ans,a[i]);
		}
	}
	cout<<ans;
	return 0;
}

