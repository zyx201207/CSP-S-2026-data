#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2*1e5+10;
struct ch{
	long long a;
	char c;
}a[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	unsigned long long ans=0,cnt=0;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].c;
		cnt+=a[i].a;
	}
	int i=1,j=n,ai=0,aj=0;
	
	int x=0,y=0;
	cnt+=a[i].a+a[j].a;
	while(x+y<=cnt&&i<j){
		if(a[i].a>=a[j].a){
			
			if(a[i].c!=a[j].c){
				ans+=a[j].a-x+y;
			}
			
			if(x>y){
				j--;
				//cnt+=a[j].a;
			}
			else{
				j--,i++;
				//cnt+=a[i].a+a[j].a;
			}
		}else{
			//x+=a[i].a,y+=a[j].a;
			if(a[i].c!=a[j].c){
				ans+=a[i].a-y+x;
			}
			
			i++;
			//cnt+=a[i].a;
		}
		x+=a[i].a,y+=a[j].a;
		//cout<<ans<<'\n';
	}
	
	//cout<<'\n';
	cout<<ans;
	return 0;
}
