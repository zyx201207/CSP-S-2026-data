#include<bits/stdc++.h>
using namespace std;
int n;
int o;
int ans=0;
int a[1000005];
char c[1000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",n);
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
	}
	for(int j=0;j<n;j++){
		if(c[j]==c[j+1]){
			o+=1;
		}
	}
	if(o==n){
		cout << 0;
		return 0;
	}
	for(int x=0;x<n;x++){
		ans+=a[x];
	}
	sort(a[0],a[n]);
	ans-=a[0];
	printf("%d",ans);
	return 0;
} 
