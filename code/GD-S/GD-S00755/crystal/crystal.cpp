#include<bits/stdc++.h>
using namespace std;
int a[500001],b[500001],sum=1,n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m>>a[1];
	for(int i=2;i<=n;i++)
		cin>>a[i];
	if(m==0){
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=2;i<=n;i++){
		int t=0,s=1,j=i-1;
		while(t<m&&j>=1){
			t+=a[i]-a[j];
			s++;
			j--;
		}
		sum=max(sum,s);
	}
	cout<<sum<<endl;	
	return 0;
}
