#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long a[300009],f=0;
	char c[300009];
	cin>>n;
	for(int i=1 ;i<=n; i++){
		cin>>a[i]>>c[i];
	}
	int x=n;
	for(int i=1; i<=n;){
		if(a[i]==0){
			i++;
		}
		else{
			if(a[x]>a[i]){
				if(c[x]!=c[i]){
					a[x]-=a[i];
					f+=a[i];
					a[i]=0;
				}
				else{
					a[x]-=a[i];
					a[i]=0;
				}
			}
			else{
				if(c[x]!=c[i]){
					a[i]-=a[x];
					f+=a[x];
					a[x]=0;
					x--;
				}
				else{
					a[i]-=a[x];
					a[x]=0;
					x--;
				}
			}
		}
	}
	cout<<f;	     
}
