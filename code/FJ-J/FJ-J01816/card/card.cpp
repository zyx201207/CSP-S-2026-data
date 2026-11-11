#include<bits/stdc++.h>
using namespace std;
int a[500050]={};
int num[300050]={};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++){
			a[j]=-2;
		}
		for(int j=i;j<n;j++){
			for(int y=j;y>=i;y--){
				if(a[y]==a[j]&&y!=j){
					for(int h=y;h<j;h++) a[h]=-1;
					break;
				}
			}
		}
//		for(int j=i;j<n;j++){
//			if(a[j]>0){
//				for(int s=j+1;s<n;s++){
//					if(a[j]==a[s]) a[s]=-1;
//				}
//			}
//		}
		for(int j=i;j<n;j++){
			if(a[j]>0){
				int q=a[j];
				num[q]++;
			}
		}
//		for(int j=0;j<n;j++){
//			cout<<a[j]<<" ";
//		}
//		cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
}
