#include<bits/stdc++.h>
using namespace std;

const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],b[M],c[N];
bool ch= 0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=n;
	while(k--){
		int cnt=0;
	for(int i=1;i<=n;i++){
		if(cnt==0){
			c[cnt++]=a[i];
		}
		else{
			int zz=cnt;
			for(int j=0;j<zz;j++){
				
				if(c[j]==a[i]){
					c[j]=0;
					ch=1;
				}
				if(ch==1){
					 c[i]=0;
					 cnt--;
				}
			}
			c[cnt++]=a[i];
		}
	}
	for(int i=0;i<cnt;i++){
		b[c[i]]++;
	}
}
for(int i=1;i<=m;i++) cout<<b[i]<<" ";
} 
