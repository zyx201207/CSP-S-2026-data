//GZ-J00352 遵义市第四中学  罗永淇 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,N1=3e5+4;
int a[N],n,m,t[N1][5];
int main(){
	freopen("card","r",stdin);
	freopen("card","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]][1]=i;
	}
	for(int i=1;i<=n;i++){
		int cnt=i;
		while(cnt<=n){
			if(t[a[cnt]][1]>cnt){
				cnt=t[a[cnt]][1];
			}	
			t[a[cnt]][2]++;
			cnt++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i][2]<<' ';
	}
	return 0;
}
