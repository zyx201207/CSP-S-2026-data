#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long r=0;
	cin>>n;
	int a[1000001];
	char b[1000001];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;n>1;){
		if(b[i]!=b[n+1-i]){
			if(a[i]>a[n+1-i]){
				r+=a[i]-a[n+1-i];
				a[i]-=a[n+1-i];
				n--;
			}else if(a[i]<a[n+1-i]){
				r+=a[n+1-i]-a[i];
				a[n+1-i]-=a[i];
				i++;
				n--;
			}else{
				r+=a[i];
				i++;
				n--;
			}
		}
		else{
			if(a[i]>a[n+1-i]){
				a[i]-=a[n+1-i];
				n--;
			}else if(a[i]<a[n+1-i]){
				a[n+1-i]-=a[i];
				i++;
				n--;
			}else{
				i++;
				n--;
			}
		}
	}
	cout<<r;
    return 0;
}
