#include<bits/stdc++.h>
using namespace std;
const long long N=1e4;
long long n,m,a[N],c[N][N],b[N],ans=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i]; 
	}
	sort(a+1,a+1+n);
	//long long i=1,j=i+m;
	//while(i<j){
	//	sum=a[i]&a[j];
	//	if(sum>)
	//}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(c[a[i]][a[j]]!=0){
				break;
			}else b[ans]=a[i]&a[j];
			c[a[i]][a[j]]=b[ans];
			ans++;
		}
	}
	
	sort(b+1,b+1+ans,cmp);
	cout<<b[1];
	return 0; 
}
