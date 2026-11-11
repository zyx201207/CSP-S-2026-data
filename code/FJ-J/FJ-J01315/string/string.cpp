#include<bits/stdc++.h>
using namespace std;
long long n,sum=0,p,q,a[300010];
char c[300010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	q=n;
	for(int i=1;i<=n/2;){
		if(a[i]>a[q]){
			if(c[i]==c[q]){
				a[i]-=a[q];
				q--;
			}else{
				sum+=a[q];
				a[i]-=a[q];
				q--;
			}
		}else if(i==q){
			cout<<sum;
			return 0;
		}else{
			if(c[i]==c[q]){
				a[q]-=a[i];
				i++;
			}else{
				sum+=a[i];
				a[q]-=a[i];
				i++;
			}
		}
	}
	cout<<sum;
	return 0;
} 
