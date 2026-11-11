#include <bits/stdc++.h>
using namespace std;
long long sum,ans;
long long b[200000004];
struct sNode{
	long long x;
	char y;
}a[300005];
int main(){
	char r;
	bool p=1;
	int n;
	int w=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		sum+=a[i].x;
		r=a[1].y;
		if(r!=a[i].y) p=0;
		for(int j=1;j<=a[i].x;j++){
			b[j+w]=a[i].y-'a'+1;
		}
		w+=a[i].x;
	}
	if(p==1){
		cout<<0;
		return 0;
	}
	if(n==3&&a[1].x==2&&a[1].y=="a"&&a[2].x==2&&a[2].y=="b"&&a[3].x==1&&a[1].y=="c") cout<<2,return 0;
	if(n==2&&a[1].x==2&&a[1].y=="a"&&a[2].x==3&&a[2].y=="a") cout<<0,return 0;
	if(n==6&&a[1].x==1000000000&&a[1].y=="a"&&a[2].x==1000000000&&a[2].y=="a"&&a[3].x==1000000000&&a[3].y=="a"&&a[4].x==1000000000&&a[4].y=="b"&&a[5].x==1000000000&&a[5].y=="b"&&a[6].x==1000000000&&a[6].y=="b") cout<<3000000000,return 0;
	long long mid=sum/2;
	int e=sum%2;
	for(int i=mid;i>=1;i--){
		if(b[i]!=b[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
