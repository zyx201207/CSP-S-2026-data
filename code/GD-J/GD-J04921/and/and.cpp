#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.ans","w",stdout);
	int n,m,ans=-1,a[200005];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+i;j<n;j++){
			for(int w=j+1;w<n;w++){
				int x=a[i] && a[j] && a[w];
				ans=max(ans,x);
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
