#include <bits/stdc++.h>
using namespace std;
int n,m,a[200003],ans=0,s;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,greater<int>());
	for(int i=1;i>1&&s<m-1;i++){
		if(a[i]){
			if(a[i]==a[i-1]){
				if(!ans){
					ans=a[i];
				}else{
					ans=(ans&a[i]);
				}
				s+=2;
				a[i]=0;
				a[i-1]=0;
			}
		}
	}
	for(int i=1;s!=m;i++){
		if(a[i]){
			if(!ans){
				ans=a[i];
				s++;
			}else{
				ans=(ans&a[i]);
				s++;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
