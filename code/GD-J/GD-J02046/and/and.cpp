#include<bits/stdc++.h>
using namespace std;
int num[200010];
bool vis[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.in","w",stdout);
	int maxn=-1;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i]; 
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j&&(num[i]&num[j])>=maxn){
					maxn=num[i]&num[j];
				}

			}		
				}
		cout<<maxn;
	}
	if(m==3){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int z=1;z<=n;z++){
					if(i!=j&&j!=i&&i!=z&&(num[i]&num[j]&num[z])>=maxn){
						maxn=(num[i]&num[j])&num[z];
					}
				}
			}
		}
		cout<<maxn;
	}
}

