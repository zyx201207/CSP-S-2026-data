#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005];
int ans[300005];
int t[500005];
int find1(int x){
	for(int i=1;i<=n;i++){
		if(t[i] == x){
			return i;
		}
	}
	return 0;
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
		
	for(int i=1;i<=n;i++){
		int now = i;
		for(int j=i;j<=n;j++){
			if(j == i){
				t[now] = a[j];
				now++;
			}else{
				if(find1(a[j]) == 0){
					t[now] = a[j];
					now++;
				}else{
					now = find1(a[j]);
				}
			}
		}
		for(int j=1;j<=n;j++){
			ans[j] = i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
