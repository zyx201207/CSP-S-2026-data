//GZ-J00135 观山湖区外国语实验中学（南校区） 安辉煌
#include <bits/stdc++.h>
using namespace std;
char c[10000],cn[10000000];
long long n,a[10000],b,minn=10000000;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];i++){
			cn[j]=c[i];
		}
	}
	for(long long i=1;i<=b;i++){
		long long cnt=0;
		for(long long j=1;j<=b;j++){
			if(cn[i]!=cn[b+1-i])
				cnt++;
		}
		minn=min(minn,cnt);
	}
	cout<<minn;
	return 0;
} 
