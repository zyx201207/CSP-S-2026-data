#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long s[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    int n;
    long long sum=0,aim=0,num=0,m,mx=0;
    cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];//输入水晶能量 
	} 
	sort(a+1,a+n+1);//排序处理 
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];//前缀和处理 
	}
	for(int r=n;r>=0;r--){
		for(int l=1;l<=r;l++){
			if(a[r]-a[l-1]>m){
			    l++;
		    }
			sum=s[r]-s[l-1];
		    num=r-l+1;
			aim=a[r]*(num);
			if(sum+m>=aim){//如果总和+步数m>=最大值*个数，说明可以合成 
				if(num>=mx) mx=num;//判断合成数是否更大 
			}
		}
	}
	printf("%lld ",mx);//输出合成物水晶个数 
	return 0;
} 
