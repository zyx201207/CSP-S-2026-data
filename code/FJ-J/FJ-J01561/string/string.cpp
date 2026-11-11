#include<bits/stdc++.h>
using namespace std;
long long yu[26],zhong[26];
int main(){
	freopen(string.in,'w');
	freend(string.out,'r');
	int n,z=0,z1,ji=0,j;
	cin>>n;
	long long a[n+1],a1[n+1];
	char c[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		a1[i+1]=a[i];
	}
	for(j=(n+1)/2;j<=n;j++){
		if(c[j]!=c[n-j]){
			break;
		}
		if(c[j+1]==c[j]){
			if(a[j]!=a[n-j]){
				if(min(a[j],a[n-j])+a[j+1]<max(a[j],a[n-j]){
					break;
				}
			}
		} 
	}
	if(j==n+1){
		cout<<0;
		return 0;
	}
	for(int i=(n+1)/2;i<=n;i++){
		z1=a[i]-a[n-i];
		if(c[i]==c[n-i]){
			if(z1+yu[c[i]-'a']==0){
				yu[c[i]-'a']=0;
			}
			else{
				if(ji==0||i!=ji+1){
			        yu[c[i]-'a']=z1+yu[c[i]-'a'];
		            ji=i;
				}
				if(i==ji+1){
				    yu[c[i]-'a']=z1+yu[ji];
			        ji=i;
				}
			}
		}else{
			yu[c[i]]=z1;		
		}
	}
	for(int i=0;i<26;i++){
		zhong2=zhong[i]+yu[i];
	}
	cout<<zhong;
	return 0;
}
