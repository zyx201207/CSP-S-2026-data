#include<iostream>
#include<vector>
using namespace std;

const int N=5e5+10;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1,0);
	vector<int> ans(m+1,0);
	bool b[N]={};
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int t=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[a[j]]==false){
				b[a[j]]=true;
			}
			else{
				t=j;
				while(b[a[t]]==false){
					j--;
					b[a[j]]=false;
				}
			} 
		}
		for(int j=1;j<=m;j++){
			if(b[j]==true){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	} 
	return 0;
}
