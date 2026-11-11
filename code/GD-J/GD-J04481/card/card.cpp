#include<bits/stdc++.h>
#define ll long long
using namespace std;
map <int,int> mp;
int a[500005];
bool b[500005];
int w[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int h=1,ans[500005]={};
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				ans[h]=a[j];
				b[a[j]]=1;
				w[a[j]]=h;
				h++;
			}else{
				
				for(int l=w[a[j]];l<h;l++){
					b[ans[l]]=0;
					ans[l]=0;
				}
				
				ans[h]=a[j];
				b[a[j]]=1;
				w[a[j]]=h;
				h++;
			}
		}
		for(int j=1;j<h;j++){
			if(ans[j]!=0){
				mp[ans[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<mp[i]<<' ';
	}
	return 0;
}

