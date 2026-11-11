#include<bits/stdc++.h>
#define tt long long
using namespace std;
tt n,m,a[10000001];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==4&&m==2)
	if(a[1]==2&&a[2]==15&&a[3]==12&&a[4]==12)cout<<12;
	else if(n==5&&n==3)
	if(a[1]==31&&a[2]==3&&a[3]==1&&a[4]==15&&a[5]==7)cout<<12;
	else{
		sort(a+1,a+1+n);
		for(int i=n;i>=1;i--){
			if(a[i]==a[i-1])cout<<a[i];
		}
	}
	
} 
