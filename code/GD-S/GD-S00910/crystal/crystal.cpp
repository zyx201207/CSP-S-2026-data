#include<iostream>
using namespace std;
int n,m,ans,a[1000000];
int main(){
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=m;i++){
		if(i==1 && i%2==0){
			ans++;
		}
		cout << ans;
	}
    //fclose("crystal.in", stdin);
    //fclose("crystal.out",stdout);
	return 0;
}
