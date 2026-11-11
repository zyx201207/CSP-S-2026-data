#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
const int M=3e5+5;
int n,m; 
int a[N];

int s[M];
bool vis[M];

int t[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(m==1){
		printf("%d",(n+1)/2);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int s[N]={0};
		int top=0;
		for(int j=i;j<=n;j++){
			top++;
			s[top]=a[j];
			for(int k=1;k<top;k++){
				if(a[j]==s[k]){
					top=k;
					break;
				}
			}
		}
		for(int j=1;j<=top;j++){
			t[s[j]]++;
		}
	}
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]==a[j] && vis[j]==0){
				for(int k=j+1;k<=i;k++){
					vis[k]=1;
				}
				break;
			}
		}
	}
	int last[M]={0};
	int l=1,r=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			t[a[i]]++;
			r++;
			last[r]=a[i];
		}
	}
	for(int i=2;i<=n;i++){
		if(vis[i]==0){
			l++;
			for(int j=l;j<=r;j++){
				t[last[j]]++;
			}
		}
		else{
			l=1,r=0;
			for(int j=1;j<=m;j++){
				vis[j]=0;
			}
			for(int j=1;j<=n;j++){
				last[j]=0;
			}
			for(int j=i;j<=n;j++){
				r++;
				last[r]=a[j];
				
//				if(s[a[j]]){
//					for(int k=s[a[j]]+1;k<=j;k++){
//						vis[k]=1;
//					}
//					r=s[a[j]];
//					s[a[j]]=0;
//				}
//				else s[a[j]]=j;
				for(int k=1;k<r;k++){
					if(a[j]==last[k]){
						r=k;
						break;
					}
				}
				
			}
			for(int j=1;j<=r;j++){
				t[last[j]]++;
			}
			for(int j=1;j<=m;j++){
				s[j]=0;
			}
		}
	}*/
	
	for(int i=1;i<=m;i++){
		printf("%d ",t[i]);
	}
	return 0;
}
