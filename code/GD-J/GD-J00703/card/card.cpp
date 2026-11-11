#include<bits/stdc++.h>
using namespace std;
const int N=5*1e6+10;
const int M=3*1e6+10;
int n,m;
int a[N];
int flag[M];
int b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int num=0;
		for(int j=i;j<=n;j++){
			if(num==0||(a[j]!=b[num])) num++,b[num]=a[j];
		}
		for(int i=1;i<=num;i++){
			flag[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<flag[i]<<" ";
	return 0;
}
