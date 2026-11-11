#include<bits/stdc++.h> 
using namespace std;
long long a[200005];
int s(int a,int b){
	int na,nb,cnt=0,q=1;
	while(a&&b){
		na=a%2;
		nb=b%2;
		if(na==nb) cnt+=q;
		q*=2;
		a/=2,b/=2;
	}
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,x=0,y=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>x){
			x=a[i];
			y=i;
		}
	}
	int q=0,p=1;
	while(x>0){
		q++;
		x/=2;
		p*=2;
	}
	p/=2;
	int cnt,sum=0;
	for(int i=0;i<q;i++){
		cnt=0;
		for(int j=0;j<n;j++){
			if((a[j]/p)%2==1) cnt++;
		}
		if(cnt>=m){
			sum+=p;
			}
		p/=2;
	}
	cout<<sum;
	
	return 0;
}
