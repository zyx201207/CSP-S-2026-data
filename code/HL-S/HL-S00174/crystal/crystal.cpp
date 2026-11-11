#include<bits/stdc++.h>
using namespace std;
int a[50000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,b=0,sum=0,ans=0,z=0;
	cin>>n>>m;
	z=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1&&a[i]!=b){
		ans=a[i]-b;
			if(m>ans){
				sum++;
			m-=ans;
			ans=0;	
			}else if(m=ans){
				sum++;
				break;
			}else{
				break;
			}
		}else if(i!=1&&a[i]==b){
			ans=a[i]-b;
			if(m>ans){
				sum++;
			m-=ans;
			ans=0;	
			}else if(m=ans){
				sum++;
				break;
			}else{
				break;
			}
			
	}
	else if(i==2&&a[i]-b<m){
				sum++;
			}
			b=a[i];
}
if(z==0){
	cout<<n;
}else{
cout<<sum;
}
	return 0;
}
