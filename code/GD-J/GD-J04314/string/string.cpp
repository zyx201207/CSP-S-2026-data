#include<bits/stdc++.h>
using namespace std;
int n;
char c[200005];
int a[1000005];
bool check(int l,int r){
	for(int i=l,j=r;i<=r,j>=l;i++,j--){
		if(c[i]!=c[j]) return 0;
	}
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int cnt=0,sum1=0,sum=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		int x;
		char b;
		cin>>x>>b;
		for(int j=cnt+1;j<=cnt+x;j++){
			c[i]=b;
		}
		cnt+=x;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=cnt/2;i++){
		if(c[i]!=c[n-i]){
			sum1++;
		}
	}
	cout<<min(sum,sum1);
	return 0;
} 
