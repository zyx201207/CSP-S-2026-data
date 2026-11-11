#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,cnt=0;
	int l=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	long long ans=a[1];
	for(int i=2;i<=m;i++){
		cnt=ans&a[l+1];
		l++;
		for(int j=l+1;j<=n;j++){
			if(ans&a[j]>=cnt){
				cnt=ans&a[j];
				l=j;
				if(cnt>=a[j+1]){
					ans=cnt;
					break;
				}
			}
			else if(cnt>=a[j]){
				ans=cnt;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
