#include<bits/stdc++.h>
using namespace std;
int n;
int a[200005];
char c[200005];
long long sum;
int ii;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	ii=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=(n+1)/2;i++){
		if(c[i]==c[ii]){
			if(a[i]>a[ii]){
				a[i]-=a[ii];
				ii--;
			}else if(a[ii]>a[i]){
				a[ii]-=a[i];
			}else{
				ii--;
			}
		}else{
			if(a[i]>a[ii]){
				a[i]-=a[ii];
				ii--;
				sum+=a[ii];
			}else if(a[ii]>a[i]){
				a[ii]-=a[i];
				
				sum+=a[i];
			}else{
				ii--;
				sum+=a[i];
			}
		}
	}
	cout<<sum;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
