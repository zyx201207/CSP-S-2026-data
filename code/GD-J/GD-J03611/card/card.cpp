#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],b[300005],ans[300005];
signed main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	memset(b,0,sizeof(b));
	a[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=0;i<n;i++){
		b[a[i]]--;
		bool delx=0;
		int deln;
		vector<bool> save(m+1,0);
		vector<int> num(m+1,0);
		for(int ii=1;ii<=m;ii++)num[ii]=b[ii];
		for(int ii=i+1;ii<=n;ii++){
			
			if(delx){
				if(a[ii]==deln){
					if(num[a[ii]]<2){
						delx=0;
						if(!save[a[ii]]){
							save[a[ii]]=1;
							ans[a[ii]]++;
						}
					}
				}
				num[a[ii]]--;		
				continue;
			}
			if(num[a[ii]]>=2){
				deln=a[ii];
				delx=1;
			}else{
				if(!save[a[ii]]){
					save[a[ii]]=1;
					ans[a[ii]]++;
				}
			}
			num[a[ii]]--;
		}

	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
