//GZ-J00469 付博苏逸 第一中学  
#include<bits/stdc++.h> 
using namespace std;
int main(){
//freopen(".in","r",stdin);
//freopen(".out","w",stdout);
	long long n,sum=0,m=0;
	cin>>n;
	int a[n];
	char s[n],z[n];
	for(int i=0;i<=n;i++){
		cin>>a[i]>>s[i]>>z[i];
	}
	for(int i=0;i<=n;i++){
		if(s[i]!=z[i]){
			z[i]=s[i];
			z++;
			break;
		}
			sum+=a[i];
	}
	

	
	
	
	
	
	return 0;
}



