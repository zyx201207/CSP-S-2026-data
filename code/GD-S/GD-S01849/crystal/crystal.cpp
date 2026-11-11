#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[500005];


void cacu1(){
	for(int i=1;i<=n;i++){

	int temp=m;
		for(int j=1;j<=n;j++){
			temp-=a[i]-a[j];
		}
		if(temp>=0) ans=i;
		if(temp<0) break;
	}
}
void cacu2(){
	for(int i=1;i<=n;i++){
		long long sum;
		sum=a[i]*(i+1)-(a[1]+a[i-1]*(i-1)/2);
		cout<<sum;
	}
}
void cacu3(){
	int d[500005];
	d[0]=0;
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+(i-1)*(a[i]*(i-1));
		if(d[i]<=m) ans=i;
		if(d[i]>m) break;
	}
}
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>n>>m;
    for(int i=1;i<n;i++){
    	cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n<=5000) cacu1();
	if(n>=5000) {
		int flag=1;
		int gap=0;
		gap=a[2]-a[1];
		for(int i=2;i<=n;i++){
			if(a[i]-a[i-1]!=gap){
				flag=0;
				break;
			}
		}
		if(flag==1)cacu2();
		if(flag==0)cacu3();


	}
	cout<<ans;

    return 0;
}

