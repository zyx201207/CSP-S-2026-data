#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],sum;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long i=1,j=n;
	while(i<=j){
		if(c[i]==c[j]){
			if(a[i]==a[j]){
				a[i]=a[j]=0;
				i++,j--;
				continue;
			}
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
				j--;
				continue;
			}
			if(a[i]<a[j]){
				a[j]-=a[i];
				a[i]=0;
				i++;
				continue;
			}
		}else{
			if(a[i]==a[j]){
				sum+=a[i];
				a[i]=a[j]=0;
				i++,j--;
				continue;
			}
			if(a[i]>a[j]){
				a[i]-=a[j];
				sum+=a[j];
				a[j]=0;
				j--;
				continue;
			}
			if(a[i]<a[j]){
				a[j]-=a[i];
				sum+=a[i];
				a[i]=0;
				i++;
				continue;
			}
		}
	}
	cout<<sum;
	return 0;
} 
