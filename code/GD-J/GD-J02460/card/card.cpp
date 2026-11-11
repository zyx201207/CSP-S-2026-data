#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500001];
vector<int>c;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++){
		int cnt=0;
		for(int l=i;l<=n;l++){
			int t=0;
			for(int j=1;j<i;j++){
				if(a[j]==a[i]){
					t=j;
					break;
				}
			}
			if(t==0) c.push_back(a[i]);
			else{
				int k=i-t;
				for(int i=1;i<=k;i++) c.pop_back();
				c.push_back(a[i]);
			}
		}
		for(int j=1;j<=c.size();j++) if(c[j]==i) cnt++;
		cout<<cnt<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
