#include<bits/stdc++.h>//大样例 
using namespace std;

int m,n,outmx=-1e12-5,mi,mx;
int a[500005];

int sam(int hsa[]){
	int suum=1;
	for(int i=1;i<n;i++)if(a[i]==a[i-1])suum++;else return suum;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	
	sort(a,a+n);
	mi=a[0];
	mx=a[n-1];
	
	for(int i=0;i<m;i++){
		if(m-i>=sam(a))a[0]++;
		sort(a,a+n);
		//cout<<i<<endl;
	}
	for(int i=mi;i<=mx+m+1;i++){
		int sum=0;
		for(int j=0;j<n;j++)if(i==a[j])sum++;
		outmx=max(outmx,sum);
		//cout<<i<<"个数："<<sum<<endl;
	}
	cout<<outmx;
}
