#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long m,n;
	struct card{
		int d;
		int cpos;
		bool isput=0;
	}a[10000005];
	struct t{
		int p=0;
		int tpos;
	};
	cin>>n>>m;
	vector<int> ans(m+1);
	
	
	for(int i=0;i<n;i++){
		cin>>a[i].d;
	}
	for(int i=1;i<=n;i++){
		t table[100005];
		int pos=0;
		for(int j=i-1;j<n;j++){
			if(!a[j].isput){
			table[pos].p=a[j].d;
			table[pos].tpos=j;
			a[j].cpos=pos;
			
			}else{
				for(int k=a[j].cpos;k<=pos;k++){
					a[table[k].tpos].isput=0;
					table[k].p=0;
					pos=a[j].cpos;
				}
			}
			pos++;
		}
		for(int k=pos;k>=1;k--){
			ans[table[k].p]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
