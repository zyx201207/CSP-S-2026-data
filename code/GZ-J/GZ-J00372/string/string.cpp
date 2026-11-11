//GZ_J00372 杨荣睿 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;

long long n,a[100000],ans=0,az=0;
char c[100000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		az=az+a[i];
	}
	
	int sum=0;
	for(int i=0;i<n;i++){
		if(c[i]==c[0]){
			sum++;
		}
	}
	if(n<=1||sum==n){
		cout<<0;
		return 0;
	}
	//奇偶
	long long ca=0;
	for(int i=0;i<n;i++){
		if(c[i]==c[i-1]){
			ca=ca+a[i];
		}else if(i!=0) break;
	}
    if(a[0]>a[1]){
	  cout<<a[1];
	  return 0;
	}
	if(a[0]<a[1]){
	  cout<<a[0];
	  return 0;
	}
	if(az%2==0) ans=az-a[0];
	else ans=az-a[0]-1;
	if(a[0]==a[1]) ans=ans-ca;
    
	cout<<ans;
	return 0;
} 
