#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005];
int check(int s[],int find,int s_len,int start){
	for(int i=start;i<s_len;i++){
		if(s[i]==find) return i;
	}return -1;
}int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		c[i]=a[i];
	}for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			c[i]=a[i];
		}for(int j=i;j<n;j++){
			int k=check(c,c[j],j,i);
			if(k==-1) continue;
			else{
				for(int w=k;w<j;w++){
					c[w]=-1;
				}
			}
		}for(int j=1;j<=m;j++){
			for(int w=i;w<n;w++){
				if(c[w]==-1) continue;
				else if(c[w]==j) b[j]++;
			}
		}
	}for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}return 0;
}
