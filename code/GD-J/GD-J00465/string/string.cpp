#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long x=0;
	long long a[200001];
	char b[200001];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1,j=n;i!=j;){
		if(b[i]!=b[j]){
			if(a[i]>a[j]){
				x+=a[j];
				a[i]-=a[j];
				j--;
			}else{
				x+=a[i];
				a[j]-=a[i];
				i++;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else{
				a[j]-=a[i];
				i++;
			}
		}
	}
	cout<<x;
	return 0;
}
