#include<bits/stdc++.h>
using namespace std;
int n,a[200001],s=0,ans=0,b[200001];
char c[200001];
string str;
int __find(int i){
	int tot=0;
	for(int k=1;k<=n;k++){
		if(tot+a[k]>=i)
			return k;
		tot+=a[k];
	}
	return -1;
}
int __find2(int i){
	int tot=s;
	for(int k=n;k>=1;k--){
		if(tot-a[k]<=i)
			return k;
		tot-=a[k];
	}
	return -1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);cout.tie(0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		s+=a[i];
//		b[i]=a[i];
//		for(int j=1;j<=a[i];i++)
//			str+=c[i];
	}
	int z=1;
	for(int i=1;i<=s/2;i+=z){
		int x=__find(i),y=__find(s-i+1);
//		z=max(b[x],b[y])-abs(b[x]-b[y]);
		if(c[x]!=c[y]){
			ans++;
//			b[x]-=z;
//			b[y]-=z;
		}
//		if(z==0) z++;
//		if(str[i]!=str[s-i+1])
//			ans++;
	}
	printf("%d",ans);
	return 0;
}
