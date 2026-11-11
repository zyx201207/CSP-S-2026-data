#include<bits/stdc++.h>
using namespace std;

long long a[2000001];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	string x;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>x[i];
	}
	for(int i=0;i<n/2;i++){
		if(a[i]==a[n-i]){
			if(x[i]==x[n-i]){
				continue;
			}else  m+=a[i];
		}else if(a[i]>a[n-i]){
			if(x[i]==x[n-i]){
				a[i]-=a[n-i];
				a[i+1]=a[i];
			}else m+=a[n-i];
		}else{
			if(x[i]==x[n-i]){
				a[n-i]-=a[i];
				a[n-i-1]=a[n-i];
			}else m+=a[n-i];
		}
	}cout<<m;
}
