#include<bits/stdc++.h>
using namespace std;
char b[20001];
int n,a[20001],sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1)cout<<"0";
	if(n==2){
		cin>>a[1]>>b[1]>>a[2]>>b[2];
		if(b[1]!=b[2]){
			sum=(a[1]+a[2])/2;
			cout<<min(max(sum,a[1])-min(sum,a[1]),max(sum,a[2])-min(sum,a[2]))<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i+i<=n;i++){
		if(b[i]!=b[n-i+1])sum+=a[i];
	}
	cout<<sum<<endl;
	return 0;
}
