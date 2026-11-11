#include <bits/stdc++.h>
using namespace std;
const int N=100000;
long long a[N],n,m;
long long jishu[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool b=1;
			for(int k=1;k<j;k++){
				if(b==0) a[k]=0;
				if(a[j]==a[k]){
					bool b=0;
				}
			}
		}
		if(a[i]!=0){
			jishu[i]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<jishu[i]<<" ";
	}
	return 0;
} 
