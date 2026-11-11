#include<bits/stdc++.h>
using namespace std;
long long n=200001,i;
long long zong=0,gai=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long a[n];
	char c[n];
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		zong+=a[i];
	}
	int x=0,y=n-1;
	i=0;
	while(x!=y){
		if(c[x]!=c[y]){
			if(a[x]>=a[y]){
				i+=a[y];
				gai+=a[y];
				a[x]-=a[y];
				a[y]=0;
			}else{
				i+=a[x];
				gai+=a[x];
				a[y]-=a[x];
				a[x]=0;
			}
		}else{
			if(a[x]>=a[y]){
				i+=a[y];
				a[x]-=a[y];
				a[y]=0;
			}else{
				i+=a[x];
				a[y]-=a[x];
				a[x]=0;
			}
			
		}
		if(i>=zong)break;
		if(a[x]==0)x+=1;
		if(a[y]==0)y-=1;
	}
	cout<<gai;
	return 0;
}
