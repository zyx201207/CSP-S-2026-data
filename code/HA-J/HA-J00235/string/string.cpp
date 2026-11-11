#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[200005];char b[200005];
	long long cnt=0;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	int j=n;
	for(int i=1;i<=n;i++){
		while(a[i]!=0){
			if(a[i]>a[j]){
				if(b[i]!=b[j]){
					cnt+=a[j];
				}
				a[i]-=a[j];
				a[j]=0;
				j--;
			}
			else if(a[i]==a[j]){
				if(b[i]!=b[j]){
					cnt+=a[j];
				}
				a[i]=0;
				a[j]=0;
				j--;
			}
			else{
				if(b[i]!=b[j]){
					cnt+=a[i];
				}
				a[j]-=a[i];
				a[i]=0;
			}
		}
	}
	cout<<cnt;
	return 0;
}
