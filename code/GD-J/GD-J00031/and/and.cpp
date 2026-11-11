#include<bits/stdc++.h>
using namespace std;
const int mx=pow(2,30);
int n,m,a[200005],b[30][200005],ccf[30],ans=mx-1,cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ans+=mx;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d" ,&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=0;pow(2,i)<=a[n];i++){
		for(int j=1;j<=n;j++){
			int t=pow(2,i);
			b[i][j]=a[j]&t;
			if(b[i][j]){
				ccf[i]++;
			}
		}
	}
	for(int i=30;i>=1;i--){
		if(ccf[i]>=m){
			for(int j=a[n];j>=1;j--){
				if(b[i][j]>0){
					ans=ans&a[j];
					cnt++;
				}
				if(cnt==m){break;}
			}
			break;
		}
	}
	cout<<ans;
	return 0; 
}
