#include<bits/stdc++.h>
using namespace std;
long long a[500008],cha[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	sort(a+1,a+1+n);											
	for(int i=2;i<=n;i++)  cha[i]=a[i]-a[i-1];	
	long long ans=0;
	if(n<=16){	
		for(int i=1,g=1;i<=n,g<=n;){
			int x=g-i;
			int sum=0;
			for(int j=1,h=i+1;j<=x;j++){
				sum+=cha[h]*j;
				h++;
			}
			if(sum<=m){
				if(g-i+1>ans) ans=g-i+1;
				g++;
			}
			else i++;
		}
		cout<<ans;
		return 0;
	}
	bool f=true;
	for(int i=3;i<=n;i++){
		if(cha[i]!=cha[i-1]) f=false;	
	} 
	if(f){
		long long  c=a[2]-a[1];
		long long s=m/c,p=0;
		for(int i=1;;i++){
			p+=i;
			if(p<=s) ;
			else{
				p-=i;
				ans=i;
				break;
			}
		}
		cout<<ans;
	}
	for(int i=n;i>=0;i--){
		long long h=0;
		for(int j=i-1;j>=0;j--){
			h+=a[i]-a[j];
			if(h>m){
				if(i-j>ans) ans=i-j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
