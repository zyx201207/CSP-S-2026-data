#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int f1[N+1];
int f[N+1];
int ans[N+1];
int a[N+1];
int s[N+1];
int s1[N+1];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	/*for(int i=1;i<=m;i++){
		f1[i]=-1;
	}*/
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		/*if(f1[a[i]]==-1){
			f1[a[i]]=i;
			f[i]=-1;
		}
		else{
			f[i]=f1[a[i]];
			f1[a[i]]=i;
		}*/
	}
	/*for(int i=0;i<n;i++){
		printf("%d ",f[i]);
	}
	cout<<endl;
	for(int i=n-1;i>=0;i--){
		ans[a[i]]=(i-f[i])+ans[a[i]];
	}
	for(int i=0;i<m;i++){
    	printf("%d ",ans[a[i]]);
	}*/
	for(int i=0;i<n;i++){
		memset(s,0,sizeof(s));
		for(int j=i;j<n;j++){
			if(s[a[j]]!=0){
				for(int z=j-1;z>=i;z--){
					if(a[z]!=a[j]){
						s[a[z]]=0;
					}
					else{
						break;
					}
				}
			}
			else{
				s[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(s[j]!=0){
				s1[j]++;
			}
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		printf("%d ",s1[i]);
	}
	return 0;
}
