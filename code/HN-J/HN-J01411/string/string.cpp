#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];	
	}
	int cnt=a[1],res=a[n],i=1,j=n;
	char s=c[1],t=c[n];
	while(i<=j){
		if(s==t){
			if(cnt==res){
				i++;
				cnt=a[i],s=c[i];
				j--;
				res=a[j],t=c[j];
			}else if(cnt>res){
				j--;
				cnt-=res;
				res=a[j],t=c[j];
			}else{
				i++;
				res-=cnt;
				cnt=a[i],s=c[i];
			}
		}else{
			if(cnt==res){
				ans+=cnt;
				i++;
				cnt=a[i],s=c[i];
				j--;
				res=a[j],t=c[j];
			}else if(cnt>res){
				ans+=res;
				j--;
				cnt-=res;
				res=a[j],t=c[j];
			}else{
				ans+=cnt; 
				i++;
				res-=cnt;
				cnt=a[i],s=c[i];
			}
		}
	}
	cout<<ans;
	return 0;
} 
