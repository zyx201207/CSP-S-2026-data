#import <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		
	}
	int s=0;
	for(int i=0;i<n;i++){
		s=a[0];
		if(a[i]>s)s=a[i];
		
	}
	if(m==1){
		cout<<s;
		
	}else{
		cout<<a[n-1];
	}
	
	return 0;
}
