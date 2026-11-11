#include<bits/stdc++.h>
using namespace std;
int n;
char c[1000005];
long long sum=0;
long long ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	int cnt=0;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=cnt+1;j<=cnt+x;j++){
			c[j]=y;
		}
		cnt+=x;
		sum+=x;
	}
	for(int i=1;i<=sum/2;i++){
		if(c[i]!=c[sum-i+1]){
			ans++;
		}
	}
	cout<<ans<<endl;
}
