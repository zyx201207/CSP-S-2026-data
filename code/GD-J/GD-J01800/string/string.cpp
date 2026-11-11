#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d%s",&a[i],&c[i]);
	}
	for(int i=1;i<=n;i++){
		if(c[i]!=c[n]){
			if(a[i]>a[n]){
				a[i]-=a[n];
				sum+=a[n];
				n--;
				i--;
			}else{
				a[n]-=a[i];
				sum+=a[i];
			}
		}else{
			if(a[i]>a[n]) a[i]-=a[n],i--,n--;
			else a[n]-=a[i];
		}
	}
	cout<<sum;
	return 0;
}
