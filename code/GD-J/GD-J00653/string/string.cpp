#include<bits/stdc++.h>
using namespace std;
int n,a[222222];
char c[222222];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n,si=0;i<=j;){
		if(a[i]>a[j]){
			if(c[i]!=c[j]){
				ans+=a[j];
			}
			si+=a[j];
			a[i]-=a[j];
			a[j]=0;
			j--;
		}else if(a[i]<a[j]){
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			si+=a[i];
			a[j]-=a[i];
			a[i]=0;
			i++;
		}else{
			if(c[i]!=c[j]){
				ans+=a[i];
			}
			si+=a[i];
			a[i]=0;
			a[j]=0;
			i++;
			j--;
		}
	}
	cout<<ans;
	return 0;
}
