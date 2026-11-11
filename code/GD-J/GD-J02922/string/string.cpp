#include<bits\stdc++.h>
#define t long long 
using namespace std;
t n,m,p,a[2000001],c,i,j,ans;
string s="";
char b[2000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}i=1,j=n;
	while(i<j){
		if(b[i]!=b[j]){
			ans+=min(a[i],a[j]);	
		}if(a[i]>a[j]) a[i]-=a[j],j--;
		else if(a[i]<a[j]) a[j]-=a[i],i++;
		else i++,j--;
	}cout<<ans;
}
