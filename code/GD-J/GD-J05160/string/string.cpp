#include<bits/stdc++.h>
using namespace std;
long long n,u=1,a[300000]={},b[300000]={},op=0,k=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	for(int i=1;i<=n;i++){
		cout<<s[i]<<endl;
	}
	op=n;
	int i=1;
	k=0;
	while(i<op){
		cout<<i<<' '<<s[i]<<' '<<a[op]<<' '<<s[op]<<' '<<k<<endl; 
		if(s[i]==s[op]){
			if(a[i]>a[op]){
				a[i]-=a[op];
				op--;
			}else if(a[i]<a[op]){
				a[op]-=a[i];
				i++;
			}else{
				i++;
				op--;
			}
		}else{
			if(a[i]>a[op]){
				a[i]-=a[op];
				k+=a[op];
				op--;
			}else if(a[i]<a[op]){
				a[op]-=a[i];
				k+=a[i];
				i++;
			}else{
				i++;
				k+=a[op];
				op--;
			}
		}
	}
	cout<<k;
	return 0;
}
