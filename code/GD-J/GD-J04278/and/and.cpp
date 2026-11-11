#include<bits/stdc++.h>

using namespace std;
int n,m;
int a[210000];
vector<int>b[40],b1[40];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;long long aaaa=(1LL<<31)-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];int lx=a[i];
		aaaa=(aaaa&a[i]);
		int j=0;
		while(lx!=0){
			++j;
			if(lx%2==1){
				b[j].push_back(i);
			}
			lx/=2;
		}
		//for(int i=31;i>=1;i--)cout<<b[i].size()<<" ";
		//cout<<endl;
	}/*
	for(int i=31;i>=1;i--){
		for(int j=0;j<b[i].size();j++){
			cout<<b[i][j]<<" ";
		}cout<<endl;
	}*/
	if(n==m)cout<<aaaa;
	long long ans=0;
	for(int i=31;i>=1;i--){
		if(m==0)break;
		if(b[i].size()>=m){
			//cout<<b[i].size()<<" ";
			//cout<<i<<" ";
			m--;
			ans|=(1LL<<(i-1));
			for(int j=0;j<b[i].size();j++){
				int lx=a[b[i][j]],ll=0;
				//cout<<b[i][j]<<" ";
				while(lx!=0){
					//cout<<lx;
					if(lx%2==1){
						b1[++ll].push_back(b[i][j]);
					}
					lx/=2;
				}
			}//cout<<"\n";
			for(int j=1;j<=31;j++){
				b[j].clear();
				b[j]=b1[j];
				b1[j].clear();
			}
			//for(int i=31;i>=1;i--)cout<<b[i].size()<<" ";
			//cout<<endl;
		}
	}
	cout<<ans;
	return 0;
}/*
5 3
31 3 1 15 7

*/
