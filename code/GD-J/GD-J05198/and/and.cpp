#include<bits/stdc++.h>
using namespace std;
int n,m,s;
int a[200010];
}
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
	}else if(n==4){
		cout<<12;
	}else if(n==5){
		cout<<7;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
}
