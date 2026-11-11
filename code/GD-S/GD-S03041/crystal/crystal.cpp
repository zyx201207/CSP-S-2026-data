#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],all,number,p,cur=1,l=1,c[500005],r;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){c[i]=a[i+1]-a[i];}
	l=1;r=1;
	for(int i=1;i<n;i++){
		if(m-p>=l*c[i]){p+=l*c[i];for(int j=1;j<=l;j++){a[j]+=c[i];}}
		while(a[l]==a[l+1] and a[l+1]<=n){l++;}
		if(l==n)break;
	}
	m-=p;p=0;
	if(l==n){
		if(m%n==0){cout<<l;}
		else{cout<<l-1;}
	}
	else{
		for(int i=l+1;i<=n;i++){
    		if(m-p>=r*c[i]){p+=r*c[i];for(int j=r+1;j<=r+l;j++){a[j]+=c[i];}}
			while(a[l+r]==a[l+1+r] and l+r+1<=n){r++;}
			if(r==n){break;} 
		}
		cout<<max(r,l);
	}
	
	return 0;
}
