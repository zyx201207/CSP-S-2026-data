#include<bits/stdc++.h>
using namespace std;
long long n,a[200007];
char c[200007];
long long sum;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]&&c[i]==c[j]){
			i++;j--;
		}else if(a[i]==a[j]){
			sum+=a[i];
			i++;j--;
		}else if(c[i]==c[j]){
			if(a[i]>a[j]){
			    a[i]=a[i]-a[j];
				j--;
			}else{
				a[j]=a[j]-a[i];
				i++;
			}
		}else{
			if(a[i]>a[j]){
				sum+=a[j];
			    a[i]=a[i]-a[j];
				j--;
			}else{
				sum+=a[i];
				a[j]=a[j]-a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
}
