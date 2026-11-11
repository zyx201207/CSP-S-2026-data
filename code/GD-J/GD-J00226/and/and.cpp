#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=2e5+10;
const int inf=0x3f3f3f3f;
long long n,m,a[N],ans=-inf,res=-1,cnt;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int s=1;s<=n;s++){
		cnt=0,res=-1;
		for(int i=s;i<=n;i++){
			if(res==-1){
				res=a[s];
				cnt++;
			}else{
				if((res&a[i])!=0){
					res&=a[i];
					cnt++;
				}
			}
			if(cnt==m)  break;
		}
		if(cnt==m)  break;
	}
	cout<<res;
	return 0;
}

