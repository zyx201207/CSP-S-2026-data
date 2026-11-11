#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
bool check(int l,int r){
	int l1=0,l2=0,k=0;
	bool vis1[200000]={0},vis2[200000]={0};
	vis1[l]=1,vis2[r]=1;
	for(int i=l;i<r;){
		int j,f=0,ma;
		for(j=i;j<=r;j++){
			if(abs(x[j]-x[i])<=d){ma=j;}
			else break;
			//cout<<abs(x[j]-x[i])<<"dff"<<endl;
		}
		if(j==i)return false;
		i=ma,l1++;
		vis1[ma]=1;
		//cout<<ma<<" ";
		//cout<<j;
	}
	//cout<<endl;
	k=0;
	for(int i=r;i>l;){
		int j,f=0,ma;
		for(j=i;j>=l;j--){
			if(abs(x[i]-x[j])<=d)ma=j;
			else break;
		}
		if(j==i)return false;
		i=ma,l2++;
		vis2[ma]=1;
		//cout<<ma<<" ";
	}
	//cout<<endl;
	bool f=0; 
	if(l2!=l1)return false;
	for(int i=1;i<=l1;i++){
		if(vis1[i]!=vis2[i]){
			f=1;
			break;
		}
	}
	if(!f)return 0;
	else return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				if(check(j,i)){
					ans++;
					//cout<<j<<","<<i<<endl;
				}
				//cout<<endl;
			}
		}
		cout<<ans<<endl;
	}
	//cout<<check(,4);
	return 0;
}

