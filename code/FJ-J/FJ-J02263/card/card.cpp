#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[500010],t[300010],ans[300010],f[500010];
int main(){
	ios::sync_with_stdio(),cin.tie(),cout.tie();
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=500&&m<=200){
		for(int i=1;i<=n;i++){
			int now=i;
			for(int j=i;j<=n;j++){
				t[a[j]]++;
				if(t[a[j]]==2){
					t[a[j]]=0;
					now=j;
				}
			}
			for(int j=now;j<=n;j++){
				ans[a[j]]++;
			}
			for(int j=1;j<=m;j++){
				t[j]=0;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	}else{
		
	}
	return 0;
} 
//4 3
//1 2 1 3

//10 3
//3 1 2 1 3 2 3 1 2 1


//sfwy_ 



