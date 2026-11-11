#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
bool a[N][31],ans[30];
int b[N];
void prepare(int x,int i){
	int cnt=30;
	while(x){
		if(x%2==1) a[i][cnt]=1;
		x/=2;
		cnt--;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		prepare(x,i);
	}
	for(int i=0;i<31;i++){
		int k=0;
		for(int j=1;j<=n;j++){
			if(b[j]>cnt) b[j]=cnt;
			if(b[j]==cnt&&a[j][i]){
				k++;
				b[j]=cnt+1;
			}
		}
		if(k<m) ans[i]=0;
		else{
			ans[i]=1;
			cnt++;
		}
	}
	int k=1;
	int tot=0;
	for(int i=30;i>=0;i--){
		if(ans[i]) tot+=k;
		k*=2;
	}
	cout<<tot;
	return 0;
}
