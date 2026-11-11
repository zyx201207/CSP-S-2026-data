#include<bits/stdc++.h>
using namespace std;
int n,m,x,ans=2147483647,cnt=0;
int a[200005];
int aa[200005];
int c[200005][31];
int s[31];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		aa[i]=a[i];}
	sort(a+1,a+n+1,cmp);
	sort(aa+1,aa+n+1,cmp);
	
	int ii=1;         
	for(ii=1;;ii++){
		if(a[1]==0){
			break;
		}
		c[1][ii]=a[1]%2;
		a[1]/=2;
	}ii-=1;
	
	for(int i=2;i<=n;i++){ 
		for(int j=1;;j++){
			if(a[i]==0)break;
			c[i][j]=a[i]%2;
			a[i]/=2;
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=ii;j>=1;j--){
//			cout<<c[i][j];
//		}cout<<endl;
//	} 
	for(int j=ii;j>=1;j--){  
		for(int i=1;i<=n;i++){
			if(c[i][j]==1){
				s[j]++;
			}
		}
		if(s[j]>=m){
			for(int i=1;cnt<=m;i++){
				if(c[i][j]==1){
					cnt++;
					if(cnt>m)break;
					ans=ans&aa[i];
				}
			}
			break;
		}
		
	}
	cout<<ans;
	return 0;}
