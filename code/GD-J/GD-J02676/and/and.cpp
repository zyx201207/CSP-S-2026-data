#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int a[100000]={ },b[100000]={ };
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int x=0,y=0,maxn=0;
	sort(a+1,a+1+n-1);
	if(m==1){
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	for(int i=0;i<m;i++){
		if(n%2==0){
			b[i]=max(a[n/2],a[n/2+1]);
			b[i+1]=min(a[n/2],a[n/2+1]);
			if(b[i]==a[n/2]) a[n/2]=0;
			else a[n/2+1]=0;
			sort(a+1,a+1+n-1);
		}else{
			b[i]=a[n/2];
			a[n/2]=0;
			sort(a+1,a+1+n-1);
		}
	}
	int sum=b[0];
	for(int i=0;i<m;i++){
		sum=sum&b[i];
	}
	cout<<sum;
	return 0;
} 
