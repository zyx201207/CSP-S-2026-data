/*GZ-j00634 ·ë»¸î£*/
#include<bits/stdc++.h> 
using namespace std;
int a[200010];
bool cmp(int a,int b){
	return a>b;
}
int bei(int x){
	while(x!=2){
		if(x%2==1){
			return 0;
		}
		x=x/2;
	}
	return 1;
} 
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x=0;
		cin>>x;
		a[i]=x;
	}
	sort(a+1,a+1+n,cmp);
	int mm=1;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1]){
			if(mm==m){
				cout<<ans;
				return 0;
			}
			ans=a[i];
			mm++;
		}else if(bei(a[i]+a[i-1]+1)){
			continue;
			}else{
				ans=ans&a[i];
				mm++;
			}
	}
	cout<<0;
	return 0;
}
