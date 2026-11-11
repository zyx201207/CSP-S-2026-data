#include<bits/stdc++.h>
using namespace std;
int a[100086],tong[10050],tongg[100580];
bool sz[100050];
int main(){
	freopen("card1.in","r",stdin);
	freopen("card1.out","w",stdout);
	int n,m;
	cin >>n >> m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}for(int i=1;i<=n;i++){
		memset(sz,0,sizeof sz);
		int ans=n-i;
		for(int j=i;j<=n;j++){
			if(sz[a[j+i]]==true){
				ans-=(j-tong[a[j]]);
			}else{
				sz[a[j]]=true;
				tong[a[j-i]]=a[j];
			}
		}tongg[ans]+=1;
	}
	for(int i=1;i<=m;i++){
		cout << tongg[i]<<" ";
	}
	return 0;
}
