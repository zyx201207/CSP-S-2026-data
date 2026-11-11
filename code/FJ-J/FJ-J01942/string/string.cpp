#include<bits/stdc++.h>
using namespace std;
long long n,a[200010][3],z,ans;
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i][2]>>c[i];
		z+=a[i][2];
		a[i][0]=a[i-1][0]+a[i][2];
	}
	for(int i=n;i>=1;i--){
		a[i][1]=a[i+1][1]+a[i][2];
	}
	z=z/2;
	long long j=n,i=1,k=0,o=0;
	while(k<z){
		o=k;
		k=min(min(a[i][0],a[j][1]),z);
		if(!(c[i]==c[j])){
			ans+=(k-o);
		}
		if(a[i][0]>k){
			j--;
		}else if(a[j][1]>k){
			i++;
		}else{
			i++;
			j--;
		}
	}
	cout<<ans;
}
