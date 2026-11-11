//GZ-J00469 付博苏逸 第一中学  
#include<bits/stdc++.h> 
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
	long long n,sum=0,m=0;
	cin>>n;
	int a[n];
	char s[n],z[n];
	for(int i=0;i<=n;i++){
		cin>>a[i]>>s[i]>>z[i];
		sum+=a[i];
	}
	for(int i=0;i<=n;i++){
		if(s[i]!=z[i]){
			z[i]=s[i];
		
			break;
		}
			sum+=a[i];
	}
	int r=n/2;
	for(int i=0;i<sum;i++){
		if(s[i]!=a[i]){
	
		a[i]=s[i];
	
		break;
	}
	sum+=z[i];
		}
	cout<<sum;
	
	
	
	return 0;
}



