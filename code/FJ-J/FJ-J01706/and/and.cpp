#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,t,m;
	cin>>n>>m;
	int a[n][31],t1[n];
	for(int i=0;i<n;i++) for(int j=0;j<=30;j++) a[i][j]=0;
	for(int i=0;i<n;i++){
		cin>>t;
		t1[i]=t;
		int j=0;
		while(t!=0){
			a[i][j]=t%2;
			t/=2;
			j++;
		}
	}
	int ans;
	bool flag=true;
	for(int j=29;j>=0;j--){
		int s=0;
		for(int i=0;i<n;i++) if(!a[i][30]) s+=a[i][j];
		if(s>m){
			ans=INT_MAX;
			for(int i=0;i<n;i++) if(a[i][j]==0) a[i][30]=1;
			for(int i=0;i<n;i++) if(a[i][j]&&!a[i][30]) ans&=t1[i];
			flag=false;
		}	
		else if(s==m){
			ans=INT_MAX;	
			for(int i=0;i<n;i++) if(a[i][j]&&!a[i][30]) ans&=t1[i];
			flag=false;
			break;
		}
	}
	if(flag) cout<<0;
	else cout<<ans;
	return 0;
} 
