#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N],mx,s,mn=INT_MAX,vis[N],cnt;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1) {
		printf("%d",a[n]);
		return 0;
	}else if(m==n){
		s=a[1];
		for(int i=2;i<=n;i++) s&=a[i];
		cout<<s;
		return 0;
	}else if(m==n-1){
		s=a[2];
		for(int i=3;i<=n;i++) s&=a[i];
		cout<<s;
		return 0;
	}else if(m==2){
		int cnt=2,b[N]={0},l=1;
		for(int i=1;i<=n;i++){
			if(a[i]<cnt) b[i]=l;
			else if(a[i]>=cnt){
				l++;
				cnt*=2;
				b[i]=l;
			}
		}for(int i=n;i>=2;i--){
			if(b[i]==b[i-1]) {
				a[i]&=a[i-1];
				cout<<a[i];
				return 0;
			}
		}
		cout<<0;
		return 0;
	}else {
		s=a[1+n-m];
		for(int i=2+n-m;i<=n;i++) s&=a[i];
		cout<<s;
		return 0;
	}
	return 0;
}
