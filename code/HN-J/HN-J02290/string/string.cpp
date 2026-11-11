#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans=0,f=0,s=0;
char c[200005];
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]==c[n+1]){
			if(a[i]>a[n-i+1]){
				ans+=a[i];
				a[n-i+1]-=a[i];
			}
			if(a[i]<a[n-i+1]){
				ans+=a[n-i+1];
				a[i]-=a[n-i+1];
			}	
		}
 }
	for(int i=1;i<=n;i++)
		if(a[n-i+1]!=0||a[i]!=0)
			s++;
	ans+=s;
	if(s==1||s==0){
		cout<<"0";
		return 0;
	}
	cout<<ans-1;
	return 0;
}
