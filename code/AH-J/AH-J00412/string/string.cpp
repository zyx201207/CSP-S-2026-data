#include<iostream>
#include<cmath>
#include<cstdio>
using namespace std;
long long a[1000005];
char c[1000005];
	long long n,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,j=n;
	while(1){
		if(i>j){
			break;
		}
		if(c[i]==c[j]){
			if(a[i]<a[j]){
				i++;
				a[j]-=a[i];
			}else if(a[i]>a[j]){
				j--;
				a[i]-=a[j];
			}else{
				i++;
				j--;
			}
		}else{
			if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++;
			}else if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else{
				ans+=a[i];
				i++;
				j--;
			}
		}
	}
	cout<<ans;
}
