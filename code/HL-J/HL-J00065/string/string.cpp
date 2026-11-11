#include<bits/stdc++.h>
using namespace std;
int n,z;
long long cnt;
int a[200010];
char c[200010];
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cin>>c[i];
	}
	for(int i=1;i<=n/2;i++){
		if(c[i]!=c[n-i+1]){
			if(a[i]<a[n-i+1]){
				cnt+=a[n-i+1];
				cnt-=a[i];
				a[n-i+1]-=a[i];
				n++;
			}
			else if(a[n-i+1]<a[i]){
				cnt+=a[i];
				cnt-=a[n-i+1];
				a[i]-=a[n-i+1];
				i--;
			}
			else{
				cnt+=a[i];
			}
		}
		else{
			if(a[i]<a[n-i+1]){
				a[n-i+1]-=a[i];
				n++;
			}
			else if(a[n-i+1]<a[i]){
				a[i]-=a[n-i+1];
				i--;
			}
			
		}
	}
	cout<<cnt;
	return 0;
}