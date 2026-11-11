#include<bits/stdc++.h>
using namespace std;
long long n,a[200008],l,x,y,xx,yy,ans,k;
char c[200008],d[100000008];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(a[i]>500)
			k=1;
		l+=a[i];
	}if(k==1){
		if(l%2==0){
			for(int i=1;i<=n;i++){
				xx+=a[i];
				if(xx==l/2){
					x=i;
					y=i+1;
					if(c[x]!=c[y]){
						if(a[x]<a[y]){
							x--;
							ans+=a[x];
						}if(a[x]>a[y]){
							y--;
							ans+=a[y];
						}if(a[x]==a[y]){
							x--;
							y--;
							ans+=a[x];
						}
					}
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i];j++){
				d[yy+j]=c[i];
			}
			yy+=a[i];
		}
		for(int i=1;i<=l/2;i++){
			if(d[i]!=d[l+1-i])
				ans++;
		}
		cout<<ans;
	}
	return 0;
} 
