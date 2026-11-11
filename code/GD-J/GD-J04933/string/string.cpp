#include <bits/stdc++.h>
using namespare std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,cnt=0,num=0;
	int a[100005];
	string b[100005],c[10000005];
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>b[i];
		for(int j=1;j<=a[i];j++){
			c[j]=b[i];
			cnt++;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(c[i]!=c[cnt+1-i]){
			num++;
		}
		
	}
	cout<<num;
	return 0;
}
