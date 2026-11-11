#include<iostream>
using namespace std;
int n,m,a[200005];
bool f(int x,int y){
	for(int i = x;i<=y;i++){
		for(int j = i;j<=n;j++){
			if(a[i]==a[j]){
				return false;
			}
		}
	}
	return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdin);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}
	int cnt[200005];
	for(int i = 1;i<=n;i++){
		for(int j= 1;j<i;j++){
			if(f(j,i)){
				cnt[a[i]] +=1;
			}
		}
	} 
	for(int i = 1;i<=n;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
