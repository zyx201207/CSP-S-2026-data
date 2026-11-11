#include<bits/stdc++.h>
using namespace std;
long n,a[2000005],cnt;
char k[2000005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>k[i];
	}
	int i=1,j=n;
	while(i<j){
		if(k[i]!=k[j]){
			if(a[i]>a[j]){
				cnt+=a[j];
				a[i]-=a[j];
				j--;
			}
			if(a[i]<a[j]){
				cnt+=a[i];
				a[j]-=a[i];
				i++;
			}
			if(a[i]==a[j]){
				cnt+=a[i];
				i++;
				j--;
			}
		}
		else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}
			if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			if(a[i]==a[j]){
				i++;
				j--;
			}
		}
	}
	cout<<cnt;
	return 0;
}
