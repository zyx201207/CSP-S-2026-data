#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int fl=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])fl=0;
	}
	if(fl){
		int num[m+2];
		for(int j=1;j<=n;j++){
			num[a[j]]++;
		}
		for(int i=1;i<=n;i++){
			num[a[i-1]]--;
			for(int j=1;j<=m;j++){
				if(num[a[j]]>=1)ans[a[j]]++;
			}			
		/*	int im[m+5]={0};
			for(int j=id;j<=n;j++){
				if(im[a[j]])continue;
				ans[a[j]]++;
				im[a[j]]=1;
			//	v.push_back(a[j]); 
			}
			/*for(int j=0;j<v.size();j++){
				im[v[i]]=0;
			}*/
		}
	}else{
		for(int i=1;i<=n;i++){
			int fd=a[i],id=i;
			for(int j=i+1;j<=n;j++){
				if(a[j]==fd){
					id=j;
				}
			}
			int im[m+5]={0};
			for(int j=id;j<=n;j++){
				if(im[a[j]])continue;
				ans[a[j]]++;
				im[a[j]]=1;
			//	v.push_back(a[j]); 
			}
			/*for(int j=0;j<v.size();j++){
				im[v[i]]=0;
			}*/
		}
	}
	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
} 
/*10 3
3 1 2 1 3 2 3 1 2 1

4 3
1 2 1 3*/
