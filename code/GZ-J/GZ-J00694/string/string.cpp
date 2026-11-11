//马浩然 六盘水市第一实验中学 GJ-J00694 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int *a=new int [n+5];
	char *c=new char [n+5];
	int *ans=new int [n+5];
	for (int i=0;i<n;i++){
		cin>>a[i];
		cin>>c[i];
		c[i]=a[i]*c[i];
		//ans+=c[i];
	}
	
	
//	ans=c[0];
	for (int i=n;i>0;i--){
		ans[i]=c[-i];
	}
	cout<<ans<<'\n';
	
	delete []a;
	delete []c;
	return 0;
} 
