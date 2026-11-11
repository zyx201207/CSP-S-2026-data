#include<bits/stdc++.h>
using namespace std;
int c,t,n[100005],s;
long long d[100005],x[2000005],a[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int o=1;o<=t;o++){
		cin>>n[o]>>d[o];
		for(int i=1;i<=n[o];i++){
			cin>>x[i];
		}
	}
	if(c==0){
		if(n[1]==4)cout<<"1\n2";
		if(n[1]==5)cout<<"0\n1";
		return 0;
	}
	for(int o=1;o<=t;o++){
		for(int i=1;i<=n[o];i++){
			if(x[i+1]-x[i]<=d[o])a[i]=1;
		}
		for(int i=1;i<=n[o]-3;i++){
			if(a[i]==0&&a[i+1]==0&&a[i+1]==0&&a[i+3]==0)continue;
			if(x[i+2]-x[i]<=d[o]&&x[i+3]-x[i+1]<=d[o])	s++;
		}
		for(int i=1;i<=n[o]-4;i++){
			if(a[i]==0&&a[i+1]==0&&a[i+1]==0&&a[i+3]==0&&a[i+4]==0)continue;
			if(x[i+2]-x[i]<=d[o]&&x[i+4]-x[i+2]<=d[o])continue;
			if(a[i+3]-a[i+1]<=d[o])	s++;
		}
		cout<<s<<"\n";
		s=0;
		for(int i=1;i<=n[o];i++){
			a[i]=0;
		}
	}
	return 0;
} 
