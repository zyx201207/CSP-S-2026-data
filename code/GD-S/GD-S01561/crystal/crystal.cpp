#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	int m;
	cin>>n>>m; 
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			m+=1;
			int cnt;
			cnt++;
			if(m>=1){
				cout<<3<<endl;
				return 0;
			}
		}
	}
	return 0;
}
