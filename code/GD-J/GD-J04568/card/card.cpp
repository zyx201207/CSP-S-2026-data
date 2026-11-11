#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N];
long long ans[300005];
bool used[300005];
long long st[N];
long long top=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(used[a[j]]){
				while(st[top]!=a[j]){
					used[st[top]]=false;
					top--;
				}
			}else{
				top++;
				st[top]=a[j];
				used[a[j]]=true;
			}
		}
		while(top!=0){
			ans[st[top]]++;
			top--;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld",ans[i]);
	}
	return 0; 
} 
