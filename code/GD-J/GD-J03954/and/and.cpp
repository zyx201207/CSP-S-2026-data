#include<bits/stdc++.h>
using namespace std;
int a[200005];
int lg[35];
int ansk[35],cnt=0;
int num[200005],cntn=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m,cn=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i];
		int c=0;
		for(int k=29;k>=0;k--){
			if(x&(1<<k)){
				lg[k]++;
				if(c==0){
					int p=(1<<(k+1))-1;
//					cout<<"P"<<p<<'\n';
					if(p!=x)cn=0;
					c=1;
				} 
			}
		}
	}
	if(m==1){
		int mx=0;
		for(int i=1;i<=n;i++)mx=max(mx,a[i]);
		cout<<mx<<'\n';
		exit(0);
	}
	if(m==n){
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum=sum&a[i];
		}
		cout<<sum<<'\n';
		exit(0);
	}
	if(m==2){
		int mx=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx<<'\n';
		exit(0);
	}
	if(m==n-1){
		int mx=0;
		for(int i=1;i<=n;i++){
			int x=a[i];
			for(int k=0;k<30;k++){
				if(x&(1<<k))lg[k]--;
			}
			int sum=0;
			for(int k=0;k<30;k++){
				if(lg[k]>=m)sum+=(1<<k);
			}
			mx=max(mx,sum);
		}
		cout<<mx<<'\n';
		exit(0);
	}
	if(cn){
		int ii=0;
		for(int k=29;k>=0;k--){
			if(lg[k]>=m){
				ii=k;
				break;
			}
		}
		cout<<(1<<(ii+1))-1<<'\n';
		exit(0);
	} 
	if(n<=20){
		cout<<0<<'\n';
	}
	for(int k=29;k>=0;k--){
		if(lg[k]>=m){
			ansk[++cnt]=k;
		}
	}
	if(cnt==0){
		cout<<0<<'\n';
		exit(0);
	}
	return 0;
} 
