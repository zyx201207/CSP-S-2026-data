#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,a[N];
char c[N];
ll ans;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
//		s[i]=s[i-1]+a[i];
	}
	for(int i=1,j=n;i<j;){
//		for(int k=i;k<=j;k++){
//			printf("%d %c\n",a[k],c[k]);
//		}
//		printf("\n");
		if(a[i]!=a[j]){
			if(c[i]!=c[j]) ans+=min(a[i],a[j]);
			if(a[i]>a[j]){
				a[i]=a[i]-a[j];
				j--;
			}else{
				a[j]=a[j]-a[i];
				i++;
			}
		}else{
			if(c[i]!=c[j]) ans+=a[i];
			i++,j--;
		}
	}
	cout<<ans;
	return 0;
}
/*
9
6 x
1 q
8 h
10 k
5 o
1 i
5 u
4 f
2 r
*/
