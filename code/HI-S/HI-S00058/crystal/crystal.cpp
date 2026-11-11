#include<bits/stdc++.h>
using namespace std;
long long n,m,t,p,mi,mi1,c;
long long sum;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int l=n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(1){
		sum=0; 
		for(int i=1;i<=n;i++){
			sum+=a[i];
		}
		sum+=m; 
		sum/=n;
		c=0,mi=sum;
		for(int i=1;i<=n;i++){
			if(a[i]==sum){
				c=1; 
				t=a[i]; 
				p=i; 
				break;
			}
			if(a[i]<sum){
				mi1=i;
			}
		}
		if(c==1){
			break;
		}
		else{
			n=mi1; 
		} 
	}
	int ans=0,cnt=m;
	for(int i=p;i>=1;i--){
		if(cnt>=t-a[i]){
			cnt=cnt-(t-a[i]);
			a[i]=t;
		}
		else break;
	}
	for(int i=1;i<=l;i++){
		if(a[i]==t){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
