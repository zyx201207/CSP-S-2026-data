#include<bits/stdc++.h>
using namespace std;
long long a[1000005],n,m,o,p;
char c[1000005];
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		m+=a[i];
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	int i=1,j=n;
	o=0;
	while(i<j){
		if(c[i]!=c[j]){
			if(a[i]==a[j]){
				o+=a[i];
				i++;
				j--;
			}
			else if(a[i]<a[j]){
				o+=a[i];
				a[j]-=a[i];
				i++;
			}
			else{
				o+=a[j];
				a[i]-=a[j];
				j--;
			}
		}
		else{
			if(a[i]==a[j]){
				i++;
				j--;
			}
			else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}
			else{
				a[i]-=a[j];
				j--;
			}
		}
	}
	cout<<o;
	return 0; 
}
