#include<bits/stdc++.h>
using namespace std;
int n,b,a[1000005],ans=0,maxx=-999999;
int main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>b;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int t=0;
		for(int i=1;i<=n;i++){
		    t=a[i];
		    for(int j=1;j<=n;j++){
		    	if(t==a[j]){
		    ans++;	
			}
			}
		    if(maxx<=ans){
				maxx=ans;
				ans=0;
			}
		}
	if(b==0){
		cout<<maxx;
		return 0;
	}
	if(b==1){int t=0;
		for(int i=1;i<=n;i++){
			t=a[i]+1;
			a[i]++;
		for(int j=1;j<=n;j++){
		    if(t==a[j]){
		    ans++;	
		}
		}
		if(maxx<=ans){
				maxx=ans;
				ans=0;
			}
			a[i]--;
		} 
		cout<<maxx;
		return 0;
}   
for(int i=1;i<=n;i++){

	t=a[i];
	for(int j=i;j<=n;j++){
		for(int z=1;z<=n;z++){
			if(t-a[j-1]<=b&&b>=0){
		b=b-(t-a[j-1]);
		ans++;
		a[j-1]=a[j];
		}
		}	
	t=a[j-1];
	}
	if(maxx<=ans){
		maxx=ans;
		ans=0;
	}
}
	cout<<maxx;
	return 0;
}
