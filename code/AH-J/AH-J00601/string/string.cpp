#include<bits/stdc++.h>
using namespace std;
long long a[200001];
char c[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long res=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i]>>c[i];
	for(int i=0,j=n-1;i<j;){
		if(c[i]==c[j]){
			if(a[i]>a[j]){
				a[i]-=a[j],j--;
				continue;
			}
			if(a[j]>a[i]){
				a[j]-=a[i],i++;
				continue;
			}
			if(a[i]==a[j]){
				i++,j--;
				continue;
			}
		}
		else{
			if(a[i]>a[j]){
				res+=a[j],a[i]-=a[j],j--;
				continue;
			}
			if(a[j]>a[i]){
				res+=a[i],a[j]-=a[i],i++;
				continue;
			}
			if(a[i]==a[j]){
				res+=a[i],i++,j--;
				continue;
			}
		}
	}
	cout<<res;
	return 0;
}
