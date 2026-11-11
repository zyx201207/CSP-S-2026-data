#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char b[200005];
long long c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i!=j;){
			if(a[i]>a[j]){
				if(b[i]!=b[j])c=c+a[j];
				a[i]=a[i]-a[j];
				j--;
				
			}
			else if(a[i]==a[j]){
				if(b[i]!=b[j])c=c+a[j];
				i++;
				j--;
				
			}
			else if(a[i]<a[j]){
				if(b[i]!=b[j])c=c+a[i];
				a[j]=a[j]-a[i];
				i++;
				
			}
		}
	cout<<c;
	return 0;
}
