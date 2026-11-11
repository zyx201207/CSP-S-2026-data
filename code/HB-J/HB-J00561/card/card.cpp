#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
int n,m;
int a[N];
const int M = 3e5+5;
int ans[M];
int doe[N];
bool flagA;
bool viscard[M];
int indexd[M];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	cin >> a[1];
	for(int i=2;i<=n;i++){
		cin >> a[i];
		if(a[i]>a[i-1]){
			flagA = false;
		}
	}
	if(flagA){
		for(int i=1;i<=n;i++){
			ans[a[i]]+=i;
		}
		for(int i=1;i<=m;i++){
			cout << ans[i] << " ";
		}
	}else{
		for(int i=1;i<=n;i++){
			memset(viscard,false,sizeof(viscard));
			for(int j=i;j<=n;j++){
				if(!viscard[a[j]]){
					viscard[a[j]] = true;
					indexd[a[j]] = j;
				}else{
					for(int s=indexd[a[j]];s<=j-1;s++){
						viscard[a[s]] = false;
					}
					viscard[a[j]] = true;	
				}
			}
			for(int j=1;j<=m;j++){
				if(viscard[j] == true){
					ans[j]++;
				}
			}
		}
		for(int i=1;i<=m;i++){
			cout << ans[i] << " ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
