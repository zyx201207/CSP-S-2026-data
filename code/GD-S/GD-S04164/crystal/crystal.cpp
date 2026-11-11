#include<bits/stdc++.h>
using namespace std;
long long n,m,mx=0,crystal[500005],mrs[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>crystal[i];
	}
	sort(crystal+1,crystal+n+1);
	for(int i=1;i<=n;i++){
		mrs[i]=crystal[i]-crystal[i-1];
	}
	long long l=1;
	long long sum=0; 
	for(long long r=1;r<=n;r++){
		sum+=mrs[r]*(r-l);
		while(sum>m){
			sum-=crystal[r]-crystal[l];
			l++;
		}
		mx=max(mx,r-l+1);
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
