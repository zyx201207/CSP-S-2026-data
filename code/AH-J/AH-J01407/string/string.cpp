#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=2e+5;
int a[N+10],n;
char c[N+10];
ll sum,maxn,bh,num1,num2,i1,i2,zj,minn;
bool vis[N+10];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		maxn+=a[i];
		if(2*maxn>=sum){
			bh=i;
			break;
		}
	}
	i1=1;
	i2=n;
	while(i1<=bh){
		num1+=a[i1]*(!vis[i1]);
		num2+=a[i2]*(!vis[i2]);
		vis[i1]=1;
		vis[i2]=1;
		minn=min(num1,num2);
		if(c[i1]!=c[i2]){
			if(num1==num2) zj+=num1;
			else zj+=abs(num1-num2);
		}
		num1-=minn;
		num2-=minn;
		if(num1==0) i1++;
		if(num2==0) i2--;
	}
	cout<<zj;
	return 0;
}
