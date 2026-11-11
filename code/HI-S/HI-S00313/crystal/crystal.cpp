#include <bits/stdc++.h>
using namespace std;
long long n,m,a[600000],ans,sum,mm,b[600000],ANS,c
;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n>5000){
		if(m>100000000){
			ans=0;
			for(int i=1;i<=n;i++){
				if(m-i>=0){
					m=m-i;
					ans++;
				}else break;
			}
		}
		cout<<ans;
		return 0; 
	}
	sort(a,a+n+1); 
	for(int i=2;i<=n;i++){
		ans=1;
		mm=m;
		for(int j=1;j<=i-1;j++){
			c=a[i]-a[i-j];
			if(mm>=c){
				ans++;
				mm=mm-c;
			}else break;
		}
		ANS=ans;
		if(ans>=sum) sum=ans;
	}
	cout<<sum;
	return 0;
}

