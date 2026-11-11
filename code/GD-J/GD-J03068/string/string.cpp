#include<bits/stdc++.h>
using namespace std;
long long  n,a[200010],len,js;
char t[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>t[i];
		len+=a[i];
	}
	for(int i=1,j=n;i<j;){
		if(a[i]==a[j]) {
			len-=a[i]*2;
			if(t[i]!=t[j]) js+=a[i];
			if(len==0) break;
			i++,j--;
		}
		else {
			if(a[i]>a[j]) {
				if(t[i]==t[j]) {
					a[i]-=a[j];
					j--;
				}
				else {
					js+=a[j];
					a[i]-=a[j];
					j--;
				}
				len-=2*a[j];
			}
			else {
				if(t[i]==t[j]){
					a[j]-=a[i];
					i++;
				}
				else {
					js+=a[i];
					a[j]-=a[i];
					i++;
				}
				len-=2*a[i];
			}
			if(len==0) break;
		}
	}
	cout<<js;
	return 0;
}
