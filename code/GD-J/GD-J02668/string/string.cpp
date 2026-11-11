#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
long long a[N];
char c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	long long ans=0;
	for(int i=0;i<n;i++){
		if(c[i]!=c[n-1]){
			ans+=min(a[i],a[n-1]);
			if(a[i]<a[n-1]){
				a[n-1]-=a[i];
				a[i]=0;
			}
			else if(a[i]==a[n-1]){
				a[i]=0;
				a[n-1]=0;
				n--;
			}
			else{
				a[i]-=a[n-1];
				a[n-1]=0;
				n--;
				i--;
			}
		}
		else{
			if(a[i]<a[n-1]){
				a[n-1]-=a[i];
				a[i]=0;
			}
			else if(a[i]==a[n-1]){
				a[i]=0;
				a[n-1]=0;
				n--;
			}
			else{
				a[i]-=a[n-1];
				a[n-1]=0;
				n--;
				i--;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
return 0;
} 
