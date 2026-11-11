#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005];
long long n,m,q=0;
char c1[1005],c2[1005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c1[i];
		b[n-i+1]=a[i];
		c2[n-i+1]=c1[i];
	}
	for(int i=1;i<=n;i++){
		if(c1[i]==c2[i]){
			if(a[i]>=b[i]) a[i+1]+=a[i]-b[i];
			else if(a[i]<b[i]) b[i+1]+=b[i]-a[i];
		}
		else{
			q+=min(a[i],b[i]);
			m=max(a[i],b[i])-min(a[i],b[i]);
			if(a[i]<b[i]){
				if(c2[i]!=c1[i+1]){
					q+=m;
					a[i+1]-=m;
				}
				else a[i+1]-=m;
			}
			else if(a[i]==b[i]) b[i+1]+=m;
			else{
				if(c2[i+1]!=c1[i]){
					q+=m;
					b[i+1]-=m;
				}
				else b[i+1]-=m;
			}
		}
	}
	cout<<q/2;
	return 0;
}
