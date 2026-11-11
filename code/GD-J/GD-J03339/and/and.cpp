#include<bits/stdc++.h>
using namespace std;
int a[200005],z[200005];
long long ans;
int s(int x){
	int i=0;
	for(i=0;1;i++){
		int q=1;for(int j=0;j<i;j++)q*=2;
		if(x<q)return i-1;
	}
}
int main(){
	freopen("and.in","r",stdin);freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){cout<<a[n];return 0;}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]&a[j]>ans)ans=a[i]&a[j];
			}
		}
		cout<<ans;return 0;
	}
	for(int i=1;i<=n;i++){
		z[i]=s(a[i]);
	}
	int sum=0,p=z[n],k=n;
	for(int j=p;j>=0;j--){
	    for(int i=1;i<=k;i++){
		    if(z[i]==p)sum++;
	    }
	    if(sum==m){
	    	ans=a[j];
	    	for(int i=k-1;i>k-sum;i--)ans=ans&a[i];
	    	break;
	    }
	    else if(sum>m){
	    	for(int i=k-1;i>k-sum;i--)ans=ans&a[i];
	    	break;
		}
	}
	cout<<ans;return 0;
}
