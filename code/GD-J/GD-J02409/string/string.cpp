#include<bits/stdc++.h>
using namespace std;
long long n; 
long long a[200005];
char c[200005];
long long sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	int i=0,j=n-1;
	while(i<=j){
		int mi=min(a[i],a[j]);
		if(c[i]!=c[j]){
			sum+=mi;
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=mi;
				i++;
			}
			else if(a[i]>a[j]){
				a[i]-=mi;
				j--;
			}
		}
		else{
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=mi;
				i++;
			}
			else if(a[i]>a[j]){
				a[i]-=mi;
				j--;
			}
		}
	}
	cout<<sum;
	return 0;
} 
