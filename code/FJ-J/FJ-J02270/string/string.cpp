#include<bits/stdc++.h> 
using namespace std;
#define endl '\n'
const int N=2e5+10;
int n,a[N],ta[N];
char c[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		ta[i]=a[i];
	}
	long long ans=0;
	int now=n;
	for(int i=1;i<=n;i++){
		int pos=a[i];
		while(pos>ta[now]){
			if(c[now]!=c[i]){
				ans+=ta[now];
			}
			pos-=ta[now];
			ta[now]=0;
			now--;
		}	
		if(c[now]!=c[i]){
			ans+=pos;
		}
		ta[now]-=pos;
	}
	cout<<ans/2;
	return 0;
}
	
