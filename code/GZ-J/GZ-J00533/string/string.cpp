//GZ-J00533 邓梓清 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
long long  n,a[200005],sum=0,minsum=0,t=1;
char c[200005],q[100000000];

int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
scanf("%lld",&a[i]);
getchar();
scanf("%c",&c[i]);
}
for(int i=1;i<=n;i++){
	for(int j=1;j<=a[j];j++){
   q[t++]=c[i];
	}
}
for(int i=1;i<=n;i++){
	if(q[i]!=q[n-i+1])
	sum++;
}
cout<<sum;
	return 0;
} 
