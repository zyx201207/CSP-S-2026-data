#include<bits/stdc++.h>
using namespace std;
int an[200005],n,m,a,b,sum;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>an[i];
	if(m==1){
		sort(an+1,an+1+n);
		cout<<an[1]<<endl;
	}
	else if(m==2){
		int ans;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)ans=an[i]&an[j];
			sum=max(sum,ans);
		}
	}else if(m==n){
		int ans=an[1];
		for(int i=2;i<=n;i++)ans&=an[i];
	}else if(m==n-1){
		for(int i=1;i<=n-m;i++){
			int ans=an[i+1];
			for(int j=i+2;j<=m;j++)ans&=an[j];
			for(int j=1;j<i;j++)ans&an[j];
			sum=max(sum,ans);
		}
	}else{
		for(int i=1;i<=n-m;i++){
			int ans=an[i];
			for(int j=i+1;j<=i+m;j++)ans&=an[j];
			sum=max(sum,ans);
		}
	}
	cout<<sum<<endl;
	return 0;
}


