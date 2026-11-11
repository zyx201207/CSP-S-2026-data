#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],top,sum,cnt,cnt1,b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){		cin>>a[i];	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		if(a[i+1]>=0 && a[i]<0){
			b[i]=a[i]*-1+a[i+1];
		}else if(a[i+1]<0 && a[i]<0){
			b[i]=a[i]*-1-a[i+1]*-1;
		}else{
			b[i]=a[i+1]-a[i];
		}
	}
	for(int i=1;i<n;i++){
		if(top==0){
			top=i;	
		}
		if(sum+(b[i]*(cnt))>m){
			if(top!=0){
				while(sum+(b[i]*(cnt))>m){
					if(sum==0)break;
					cnt--;
					sum-=(a[i]-a[top]);
					top++;
				}
			}
		}
		cnt++;
		sum+=(b[i]*(cnt));	
		cnt1=max(cnt,cnt1);
	}
	cout<<cnt1+1;
	return 0;
}