#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int cnt[200010];
int cnt2[5];
int ans;
void sovle1(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,greater<int>());
	if(m==2){
		int maxn=0;
		for(int i=1;i<=n;i++){
			for(int j=2;j<=n;j++){
				int x=a[i]&a[j];
				maxn=max(maxn,x);
			}
		}cout<<maxn;
	}if (m==n){
		int maxn=a[1];
		for(int i=2;i<=n;i++){
			maxn&=a[i];
		}cout<<maxn;
	}
	if(m==1){
		cout<<a[1];
	}bool flag=1;
	for(int i=1;i<=n;i++){
		if(a[i]>=4){
			flag=0;
			break;
		}
	}
	if (flag==1){
		for(int i=1;i<=n;i++){
			cnt2[a[i]]++;
		}if(cnt2[3]>m){
			cout<<3;
		}else if (cnt2[3]<m&&(cnt2[2]+cnt2[3])>m){
			cout<<2;
		}else if(cnt2[3]+cnt2[1]>m){
			cout<<1;
		}else cout<<0;
	}
//	cout<<n<<' '<<m<<endl;
//	for(int x=1;x<=n;x++){
//		cout<<a[x]<<' ';
//	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	sovle1();
}
