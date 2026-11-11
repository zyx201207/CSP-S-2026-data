#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","out",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}for(int i=1,j=n;i<=j;){
		if(c[i]!=c[j]){
			cout<<111;
			if(a[i]>a[j]){
				sum+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				sum+=a[i];
				a[j]-=a[i];
				i++;
			}else{
				sum+=a[i];
				i++,j--;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++,j--;
			}
		}
	}cout<<sum;
	return 0;
} 
