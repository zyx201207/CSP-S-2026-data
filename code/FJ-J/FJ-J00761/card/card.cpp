#include<bits/stdc++.h>
//#include<windows.h>
#include<string>
using namespace std;
int d[500005],ans[300005],p[500005];
bool f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			f[j]=0;
		}
		int l=0;
		for(int j=i;j<=n;j++){
			if(f[p[j]]==0){
				l++;
				f[p[j]]=1;
				d[l]=p[j];
			}
			else{
				while(d[l]!=p[j]){
					f[d[l]]=0;
					//cout<<d[l];
					//Sleep(500);
					l--;
				}
			}
			//10 3 3 1 2 1 3 2 3 1 2 1
//			cout<<p[j]<<"-";
//			for(int j=1;j<=l;j++){
//				cout<<d[j]<<" ";
//			}
//			cout<<endl;
//			for(int j=1;j<=m;j++){
//				cout<<f[j]<<" ";
//			}
//			cout<<endl;
		}
		for(int j=1;j<=m;j++){
			if(f[j]==1)ans[j]++;
		}
//		cout<<endl;
	}
	for(int j=1;j<=m;j++){
		cout<<ans[j]<<" ";
	}
	return 0;
}
