#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],c[200005],ans;
char b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		c[i]=a[i];
	}
	int j=n,yz=a[1],yy=a[n];
	for(int i=1;i<=n;){
		if(b[i]!=b[j]){
			if(yz>yy){
				ans+=yy;
				j--;
				yz-=yy;
				yy=a[j];
			}
			else if(yz<yy){
				ans+=yz;
				i++;
				yy-=yz;
				yz=a[i];
			}
			else{
				ans+=yz;
				i++;
				j--;
				yz=a[i];
				yy=a[j];
				
			}
		}
		else{
			if(yz>yy){
				j--;
				yz-=yy;
				yy=a[j];
			}
			else if(yz<yy){
				i++;
				yy-=yz;
				yz=a[i];
			}
			else{
				i++;
				j--;
				yz=a[i];
				yy=a[j];
				
			}
		}
	}
	cout<<ans/2;
	return 0;
}
