#include<bits/stdc++.h>
using namespace std;
long long int n,m;
long long int a[500005];
long long int ans;
long long int b[500005];
long long int cnt=1;
bool used[500005];
long long int answer[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(used[a[j]]==false){
				used[a[j]]=true;
				b[cnt]=a[j];
				cnt++;
				continue;
			}
			if(used[a[j]]==true){
				for(int k=1;k<=n;k++){
					if(a[j]==b[k]){
						cnt=k;
						break;
					}
				}
				for(int k=cnt+1;k<=n;k++){
					used[b[k]]=false;
					b[k]=0;
				}
			}    
		}
		for(int j=1;j<=m;j++){
			if(used[j]==true){
				answer[j]++;
			}
		}
		for(int j=1;j<=n;j++){
			used[j]=false;
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<answer[i]<<" ";
	}
	return 0;
}