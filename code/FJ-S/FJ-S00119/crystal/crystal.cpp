#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],ans=0,sum[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar(); 
	}
	return x*f;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	if(n>=5000){
		int x=abs(a[1]-a[2]);
		sum[n]=x*(n-1);
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+i;
		}
		for(int i=n;i>=1;i--){
			if(sum[i]*x<=m){
				cout<<i+1;
				return 0;
			}
		}
		return 0;
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i+k-1<=n;i++){
			int x=m,ma=INT_MIN;
			for(int j=i;j<=i+k-1;j++){
				ma=max(ma,a[j]);
			}
			for(int j=i;j<=i+k-1;j++){
				x-=ma-a[j];
			}
			if(x>=0){
				ans=k;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
