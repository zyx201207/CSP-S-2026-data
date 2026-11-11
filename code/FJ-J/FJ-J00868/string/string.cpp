#include<bits/stdc++.h>
using namespace std;
long long n,a[204800],i,j,f=0,s=0;
string c[204800];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		f+=a[i];
	}
	j=n;
	for(int i=0;i<n/2;){
		if(a[i]==0)i++;
		if(a[j]==0)j--;
		if(c[i]!=c[j]){
			if(a[i]>a[j]){
				s+=a[j];
				a[i]-=a[j];
				a[j]=0;
			}else{
				s+=a[i];
				a[j]-=a[i];
				a[i]=0;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				a[j]=0;
			}else{
				a[j]-=a[i];
				a[i]=0;
			}
		}
	}
	cout<<s;
	return 0;
} 
