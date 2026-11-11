#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdin);
	int n,s=1;
	long long m;
	cin>>n>>m;
	int a[1000010]={};
	a[0]=-200010;
	a[n+1]=200010;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n+1);
	int c=a[n/2+1];
	int z=n/2,y=n/2+2;
	for(int i=1;i<=m;i++){
		if(c-a[z]>c-a[y]){
			m-=c-a[z];
			z--;
		}else{
			m-=c-a[y];
			y++;
		}
		if(m>=0) s++;
		else break;
	}
	cout<<s;
	
	return 0;
} 
