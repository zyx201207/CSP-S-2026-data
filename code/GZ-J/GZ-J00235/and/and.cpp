//GZ-J00235 张哲睿 贵阳市新世界学校 
#include<bits/stdc++.h>
using namespace std;
int a[200011],c[32];
bool b[200011][32];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if((a[i]>>j)&1){
				b[i][j]=1;
				c[j]++;
			}
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=30;j++){
			if(b[i][j] && c[j]<m){
				a[i]-=(1<<j);
			}
		}
	}
	
	int sum=(1<<30)-1;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}
