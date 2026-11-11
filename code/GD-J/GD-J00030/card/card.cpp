#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int a[N];
int b[N][3];

int c[N];
int cnt=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cnt=0;
		for(int j=i;j<n;j++){
			if(b[a[j]][0]==0){
				c[cnt]=a[j];
				b[a[j]][0]=1;
				b[a[j]][1]=cnt;
				cnt++;
			}else{
				for(int k=cnt-1;k>b[a[j]][1];k--){
					b[c[k]][0]=0;
					c[k]=0;
					
				}
				cnt=b[a[j]][1]+1;
			}
			
		}
		
		for(int j=0;j<cnt;j++){
			b[c[j]][2]++;
		}
		for(int j=0;j<=m;j++){
			b[j][0]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i][2]<<" ";
	}
}
