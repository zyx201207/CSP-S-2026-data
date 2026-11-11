#include<iostream>
using namespace std;
long long n,a[200001],all,sum;
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++) cin>>a[i]>>c[i],all+=a[i];
	for(long long i=1,j=n,aii=all>>1;;i++){
		if(aii-a[i]<=0){
			if(aii-a[i]<0) a[i]-=(2*aii-2*a[i]-all%2);
			if(a[i]<=a[j]){
				if(c[i]!=c[j]) sum+=a[i];
				a[j]-=a[i];
				aii-=a[i];
				break;
			}else{
				if(c[i]!=c[j]) sum+=a[j];
				a[i]-=a[j];
				aii-=a[j];
				i--,j--;
			}
		}
		if(a[i]<=a[j]){
			if(c[i]!=c[j]) sum+=a[i];
			a[j]-=a[i];
			aii-=a[i];
		}else{
			if(c[i]!=c[j]) sum+=a[j];
			a[i]-=a[j];
			aii-=a[j];
			i--,j--;
		}
	}
	cout<<sum;
	return 0;
}
