#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,i,j;
char ch[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++) {
		scanf("%lld",&a[k]);
		cin>>ch[k];
	}
	i=1,j=n;
	while(i<j) {
		if(i==j) break;
		if(a[i]<=a[j]) {
			if(ch[i]!=ch[j])cnt+=a[i];
			a[j]-=a[i],a[i]=0;
		}
		else {
			if(ch[i]!=ch[j])cnt+=a[j];
			a[i]-=a[j],a[j]=0;
		}
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<cnt;
 	return 0;
} 
