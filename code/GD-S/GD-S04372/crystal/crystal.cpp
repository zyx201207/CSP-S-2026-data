#include<bits/stdc++.h>
using namespace std;
long long n,m,sjs=1,maxn,xgm;
int a[500005],b[500005];
void gulin(){
	for(int i=1;i<=n;i++){
		b[i]=a[i];
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	xgm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	int k=1;
	for(int j=2;j<=n;j++){
		gulin();
		m=xgm;
		sjs=1;
		while(m>=0){
			if(m>0&&b[j-k]<a[j]&&j-k>=1){
				m--;
				b[j-k]++;
				//cout<<j-k<<" "<<a[j]<<" "<<b[j-k]<<endl;
			}
			else if(m>=0&&b[j-k]==a[j]&&j-k>=1){
				k++;
				sjs++;
				//cout<<" "<<j-k<<" "<<a[j]<<" "<<b[j-k]<<endl;
			}
			else if(m==0||j-k<1){
				maxn=max(sjs,maxn);
				k=1;
				break;
			}
		}
//		for(int z=1;z<=n;z++){
//			cout<<b[z]<<" ";
//		}
//		cout<<endl;
	}
	cout<<maxn;
	return 0;
}
