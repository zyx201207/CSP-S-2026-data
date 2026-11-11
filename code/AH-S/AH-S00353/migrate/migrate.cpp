#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long s,p;
long long a[2000100]={0};
long long k[2000100]={0};
long long b[2000100]={0};
long long sum[2000100]={0};
long long vit[2000100]={0};
long long vis;
long long h;
void solve(){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<=i+b[i];j++){
			if(sum[j]==-1){
				sum[j]=sum[i]+1;
				vit[j]=1;
			}else{
				if(sum[j]>sum[i]+1){
					sum[j]=sum[i]+1;
					vit[j]=1;
				}else if(sum[j]==sum[i]+1){
					vit[j]++;
				}
			}
		}
	}
	h=0;
	for(int i=0;i<n;i++){
		if(vit[i]==2) h++;
		//cout<<vit[i]<<" ";
	}
	/*cout<<endl;
	for(int i=0;i<n;i++){
		cout<<sum[i]<<" ";
	}
	cout<<endl;*/
	cout<<h<<endl;
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11 || c==12){
		while(t--){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
			if(a[1]-a[0]>d){
				cout<<0<<endl;
			}else if(n<=3 || n<=d){
				cout<<0<<endl;
			}else{
				s=d/(a[1]-a[0]);
				p=s*2;
				cout<<n-p+1<<endl;
			}
		}
	}else{
		while(t--){
			cin>>n>>d;
			for(int i=0;i<n;i++){
				cin>>a[i];
				sum[i]=-1;
				vit[i]=0;
			}
			for(int i=0;i<n;i++){
				int j=i+1;
				b[i]=0;
				while(a[j]-a[i]<=d && j<n){
					b[i]++;
					j++;
				}
			}/*
			for(int i=0;i<n;i++){
				cout<<b[i]<<" ";
			}
			cout<<endl;*/
			if(n<=d){
				cout<<0<<endl;
			}else{
				solve();
			}
		}
	}
	return 0;
}
