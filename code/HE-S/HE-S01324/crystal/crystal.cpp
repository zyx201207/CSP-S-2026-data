#include<bits/stdc++.h>
using namespace std;
long long a[500005],h[500005];
int k(int m){
	for(int i=1;i<=m/2;i++){
		if((i+1)*(i+1)>m)	return i+1;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[i]=h[i-1]+a[i];
	}	
	sort(a+1,a+n+1);
	if(n>5000){
		int c=a[2]-a[1];
		cout<<k(m/c);
	}
	else{
		int ans=0;
		int J=0;
		for(int i=1;ans<=m&&i<=n;i++){
			for(int j=1;j<=i;j++){
				ans=a[i]*(i-j)-h[i]+h[j];
				J=i-j;
				if(ans>m)	break;
			}
			
		}
		cout<<J;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
