#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
int n,maxn=0,numn=0;
long long m,a[N];
bool cmp(int x,int y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){	
		for(int j=1;j<i;j++){
			int num=0;
			for(int t=j;t<i;t++){
				num+=(a[i]-a[j]);
				if(num<=m){
					if(i-t+1>numn){
						numn=i-t+1;
					}
				}
			}
			
		}	
	}
	cout<<numn;
	
	return 0;
} 
