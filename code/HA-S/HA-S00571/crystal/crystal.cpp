#include<bits/stdc++.h>
using namespace std;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int a[500005]={},b=0,f=0;
	long long  neng=m,ans=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	if(a[i]<a[i-1]){
		b=a[i-1];
		a[i-1]=a[i];
		a[i]=b;}
	}
		for(int i=1;i<=n;i++){
			f++;
		    neng-=f*(a[i+1]-a[i]);
		    a[i]=a[i+1];
		    b=i+1;
		    if(neng<=0){
		    	break;
		    }
		}
	for(int i=1;i<=f;i++){
		a[i]=a[b];
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1]){
			ans++;
		}}
		cout<<ans;	
	return 0;
}

