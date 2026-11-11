#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m,sum=0,num=0,cum=1,t=0,cnt=0,p,q,k,f;
ll a[700090];
ll b[700090];
ll c[700090];
bool cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t+=a[i];
	}
	t=t/n;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i+1];
	}
	int count=b[1];
	for(int i=1;i<=n-1;i++){
		if(count>b[i])
		count=b[i];
		if(b[i]!=b[i+1])
		cum=0;
	} 
	if(cum==1){
		for(int i=b[1];i<=n;i=i+b[1]){
			if(num<m){
				sum++;
				num+=i;
			}else{
				cout<<sum;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		c[i]=a[i]-t;
	}
	cnt=c[1];
	for(int i=1;i<=n-1;i++){
		if(cnt>c[i]&&c[i]>=0)
			cnt=c[i];	
	}
	for(int i=1;i<=n-1;i++){
		if(c[i]==cnt)
		p=a[i];
	}
	for(int i=1;i<=n;i++){
		f=p-a[i];
		if(a[i]<=p&&(num+f<m)){
			sum++;
			num+=f;
		}
	}
	cout<<sum+1;
	return 0;	
}
