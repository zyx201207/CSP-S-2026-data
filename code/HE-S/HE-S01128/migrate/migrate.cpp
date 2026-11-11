#include<bits/stdc++.h>
using namespace std;

const int maa=5e5+5;
long long d,a[maa],ans,w,num=2e18,q;
int n,c,t,f;
void bfs(int x,int y){
	if (x==y){
		if (num>q){
			ans=1;
			num=q;
			q--;
		}
		else{
			if (num==q){
				ans++;
			}
		}
	}
	for (int i=x+1;i<=y;i++){
		if (abs(a[i]-a[x])<=d){
			q++;
			bfs(i,y);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","W",stdout);
	cin >>c>>t;
	while(t--){
		w=0;
		cin >>n>>d;
		for (int i=1;i<=n;i++){
			cin >>a[i];
			if ((a[i]-a[i-1])>d && i>1){
				f=n-i;
			}
		}
		for (int i=n-f;i>=1;i--){
			for (int j=1;j<=n-f;j++){
				if (abs(a[i]-a[j])<=d || i<=j){
					w=1;
					break;
				}
				bfs (j,i);
				if (num==2){
					ans++;
				}
			}
			if (w==1){
				break;
			}
		}
		if (ans%2==0){
			cout <<ans/2<<"\n";
		}
		ans=0;
		num=0;
	}
	return 0;
} 
