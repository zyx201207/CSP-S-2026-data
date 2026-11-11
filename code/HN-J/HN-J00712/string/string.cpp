#include<iostream>
using namespace std;
int n;
const int N=200000;
char c[N];
long long a[N];
long long sum,mid;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	if(n%2==0)mid=n/2;//为双 
	else if(n%2!=0)mid=n/2+1;//为单 
		for(int i=1;i<=mid;i++){
			if(i==n+1-i)continue;
			if(c[i]!=c[n+1-i]){//如果字母不对,将mid之下的数向后扩，mid之上的数向前扩 ，小的向大扩 
				if(a[i]!=a[n+1-i]){//并且数字不对 
					if(a[i]>a[n+1-i]){
						a[n+1-i-1]-=a[i]-a[n+1-i];//后面数并没有移动 
						a[n+1-i]+=a[i]-a[n+1-i];
						c[n+1-i]=c[i];
						sum+=a[i];
					}else if(a[i]<a[n+1-i]){
						a[i+1]-=a[n+1-i]-a[i];
						a[i]+=a[n+1-i]-a[i];
						c[i]=c[n+1-i];
						sum+=a[i];
					}
				}else{
				c[n+1-i]=c[i];
				sum+=a[i];	
				}
			}else{
				if(a[i]!=a[n+1-i]){//字母对，数字不对 ,此时只需要统计增加的数字 
					if(a[i]>a[n+1-i]){
						a[n+1-i-1]-=a[i]-a[n+1-i];//后面数并没有移动 
						a[n+1-i]+=a[i]-a[n+1-i];
						sum+=a[i]-a[n+1-i];
					}else if(a[i]<a[n+1-i]){
						a[i+1]-=a[n+1-i]-a[i];
						a[i]+=a[n+1-i]-a[i];
						sum+=a[n+1-i]-a[i];
					}
				}	
			}
		} 
	cout<<sum;
	//a[n+1-i]
	return 0;
}
