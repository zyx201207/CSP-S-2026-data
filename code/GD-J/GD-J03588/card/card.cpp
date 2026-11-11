#include<iostream>
#include<cstring>
using namespace std;
int arr[10000000],ans[1000000],t[1000000];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	bool check[m+5];
	for(int i = 1;i <= n;i++){
		cin>>arr[i];
	}
	for(int i = 1;i <= n;i++){
		memset(check,0,sizeof(check));
		memset(t,0,sizeof(t));
		int idx=0;
		for(int j = i;j <= n;j++){
			if(check[arr[j]]){
				while(t[idx] != arr[j]){
					check[t[idx]] = 0;
					idx--;
				}
			}
			check[arr[j]] = 1;
			t[++idx]=arr[j];
		}
		for(int j = 1;j <= m;j++) ans[j] += check[j];
		
	}
	for(int i = 1;i <= m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
