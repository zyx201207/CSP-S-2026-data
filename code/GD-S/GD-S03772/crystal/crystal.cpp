#include<bits/stdc++.h>
#define int long long	
using namespace std;
int n,m,a[5000005],sum,q[5000005],s[5000005],vis[5000005],maxn=-1e18;
int check(int x){
	int k=m,f=0,t1=0,t2=0,flag=0,num1=0,num2=0;
	while(k>=0){
		num1=0;
		num2=0;
		flag=0;
		t1=0;
		t2=0;
		if(f==0){
			if(x-1<1){
				if(k-q[x]<0)break;
				k=k-q[x];
				x=x+1;
			}
			else if(x+1>n){
				if(k-q[x-1]<0)break;
				k=k-q[x-1];
				x=x-1;
			}
			else if(q[x-1]<=q[x]){
				if(k-q[x-1]<0)break;
				k=k-q[x-1];
				x=x-1;
			}
			else{
				if(k-q[x]<0)break;
				k=k-q[x];
				x=x+1;
			}
		}
		for(int i=x-1;;i--){
			if(i<1){
				flag=1;
				t1=0;
				break;
			}
			if(vis[i]==0){
				break;
			}
			t1++;
		}
		for(int i=x+1;;i++){
			if(i>n){
				flag=2;
				t2=0;	
				break;
			}
			if(vis[i]==0){
				break;
			}
			t2++;
		}
		for(int i=x;i<=x+t1;i++)num1+=q[i];
		for(int i=x-1;i>=x-1-t2;i--)num2+=q[i];
		if(flag==1){
			if(k-num1<0)break;
			k=k-num1;
			x=x+t1+1;
			f=2;
		}
		else if(flag==2){
			if(k-num2<0)break;
			k=k-num2;
			x=x-1-t2;
			f=1;
		}
		else if(num1<=num2){
			if(k-num1<0)break;
			k=k-num1;
			x=x+1+t1;
			f=2;
		}
		else{
			if(k-num2<0)break;
			k=k-num2;
			x=x-1-t2;
			f=1;
		}
		sum++;
		vis[x]=1;
	}
	return x;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++){
		q[i]=a[i+1]-a[i];
	}
	int l=0,r=n;
	while(l+1<r){
		int mid=(l+r)/2;
		sum=0;
		memset(vis,0,sizeof vis);
		if(mid<=check(mid)){
			l=mid;
			maxn=max(maxn,sum);
		}
		else{
			r=mid;
			maxn=max(maxn,sum);
		}
	}
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
