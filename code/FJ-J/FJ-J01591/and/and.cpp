#include <bits/stdc++.h>
using namespace std;
struct node{
	int c[35],s;
}b[200005];
int n,m,a[200005],ans=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		long long t=a[i],cnt=0;
		while(t>0){
			cnt++;
			b[i].c[cnt]=t%2;
			t/=2;
			b[i].s=cnt;
		}
	}
	/*for(int i=1;i<=n;i++){
			for(int k=1;k<=b[i].s;k++){
				cout<<b[i].c[k];
			}
			cout<<" "<<b[i].s<<endl;
	}*/
	if(m==1){
		sort(a+1,a+1+n);
		cout<<a[n];
		return 0;
	}
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int t=0;
			for(int k=1;k<=min(b[i].s,b[j].s);k++){
				if(b[i].c[k]&&b[j].c[k]){
					t+=pow(2,k-1);
				}
			}
			ans=max(t,ans);	
		}
	}
	cout<<ans;
	return 0;	
	/*if(m==3){
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			for(int o=j+1;o<=n;o++){
				int t=0;
				for(int k=1;k<=min(b[i].s,b[j].s);k++){
					if(b[i].c[k]&&b[j].c[k]){
						t+=pow(2,k-1);
					}
				}
				ans=max(t,ans);	
			}
		}
	}
	cout<<ans;
	return 0;	
	}*/
}


