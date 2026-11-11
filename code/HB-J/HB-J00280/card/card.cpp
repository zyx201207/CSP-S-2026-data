#include <bits/stdc++.h>
using namespace std;
const int N =500005;
bool flag[N];
int d[N];
int t[N];
int pos[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++)
		cin>>d[i];
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			flag[j]=false;
			pos[j]=-1;
		}
		for (int j=i-1;j<n;j++){
			if (flag[d[j]]){
				for (int z=pos[d[j]];z<j;z++)
					flag[d[z]]=false;
			}
			flag[d[j]]=true;
			pos[d[j]]=j;
		}
		for (int j=1;j<=m;j++){
			if (flag[j])
				t[j]++;
		}
	}
	
	for (int i=1;i<=m;i++)
		cout<<t[i]<<" "; 
	
	return 0;
}
