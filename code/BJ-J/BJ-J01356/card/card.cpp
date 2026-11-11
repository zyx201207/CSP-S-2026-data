#include <bits/stdc++.h>
using namespace std;
//#define int long long

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+2];
	vector<int> ans(m+2,0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		int b[n+5];
		vector<int> vis(m+1,-1);
		int end =1;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>=1){
				for(int k=vis[a[j]]+1;k<end;k++){
					vis[b[k]]=-1;
				}

				end=vis[a[j]]+1;
					//cout<<"visa="<<vis[a[j]]<<"   end="<<end<<endl;
				continue;
			}
			//cout<<a[j]<<endl;
			b[end]=a[j];
			vis[a[j]]=end;
			end++;
		}
				//cout<<111<<endl;
		for(int j=1;j<end;j++){
			//cout<<b[j]<<" ";
			ans[b[j]]+=1;
		}//out<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<endl;
	}
	
	
	return 0;
}