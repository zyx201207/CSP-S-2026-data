#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],s,j,ans,x[200005],y[200005];
char b[200005];
bool f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
    	cin>>a[i]>>b[i];
    	x[i]=x[i-1]+a[i];
		s+=a[i];
	}
    for(int i=n;i>=1;i--){
    	y[i]=y[i+1]+a[i];
	}
    for(int i=2;i<=n;i++){
		if(b[i]!=b[i-1]){
			f=0;
		}
	}
	if(f==1){
		cout<<"0";
		return 0;
	}
	j=n;
	for(int i=1;i<=n/2;i++){
		while(x[j]>s-x[i]){
			if(x[j]-a[j]<s-x[i]){
				x[j]=s-x[i];
				a[j]=x[j]-x[j-1];
			}else{
				j--;
			}
		}
		ans+=a[i];
	}
	long long an=0;
	j=0;
	for(int i=n/2;i>=0;i--){
		while(y[j]>s-y[i]){
			if(y[j]-a[j]<s-y[i]){
				y[j]=s-y[i];
				a[j]=y[j]-y[j+1];
			}else{
				j++;
			}
		}
		an+=a[i];
	}
	cout<<min(ans,an);
	return 0;
}
