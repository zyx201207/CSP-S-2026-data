#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
string b[1000000];
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,sum=0,s=0;
cin>>n;
for(int i=1;i<=n;i++){
	cin>>a[i]>>b[i];
}
string k=b[1];
for(int i=1;i<=n;i++){
	if(k!=b[i]){
		s=1;
		break;
	}
}
if(s==0){
	cout<<"0";
	return 0;
}
for(int i=1;i<=n/2;i++){
	if(b[i]!=b[n-i+1]){
		sum+=min(a[i],a[n-i+1]);
	}
	if(a[i]!=a[n-i+1]){
		sum+=max(a[i],a[n-i+1])-min(a[i],a[n-i+1]);
		//if(a[i]>=a[n-i+1]){
		//	a[n-i+2]--;
		//}
		//else{
		//	a[i+1]--;
	//	}
	}
}
cout<<sum;
}
