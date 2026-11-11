//GZ-J00646		兴义市弘毅中学		马志宸奕	 
#include<bits/stdc++.h>
using namespace std;

int n,m;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	int a[n]={0};
	for(int i=0;i<n;i++){
	cin>>a[i];
}
	sort(a,a+n);
	for(int i=0;i<n;i++){
		if(a[i]==a[i+1])
		{		
		cout<<a[i];
		return 0;
	}
	}
	
	
	return 0;
} 
