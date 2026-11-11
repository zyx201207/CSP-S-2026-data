#include<bits/stdc++.h> 
using namespace std;
#define int long long
int a[50000000],ans=0;
int aa[50000000];
bool flag=0;
stack<int> qu;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int mm=1;mm<=m;mm++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				qu.push(a[j]);
				aa[a[j]]++;
					while(aa[a[j]]>1&&!qu.empty()){
						if(qu.top()==a[j]){
							a[j]--;
						}
						qu.pop();
					}
				qu.push(a[j]);
				while(!qu.empty()){
					if(qu.top()==mm)flag=1;
					qu.pop();
				}
			memset(aa,0,sizeof(aa));
			}
			ans+=flag;
			flag=0;
		}
		cout<<ans<<" ";
		ans=0;
	}
	return 0;
}
