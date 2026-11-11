#include<bits/stdc++.h>
using namespace std;

int const N=2e5+10;
int a[N];
int c[N];
int n,m;

int dfs(int w,int b[],int len){
	if(w==-1)return 0;
	int len2=0;
	for(int i=1;i<=len;i++){
		if(b[i]&(1<<w)){
			c[++len2]=b[i];
		}
//		cout<<(b[i]&(1<<w))<<" "<<w<<" "<<b[i]<<endl;
	}
	
	if(len2>=m)return (1<<w)+dfs(w-1,c,len2);
    return dfs(w-1,b,len);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cout<<dfs(30,a,n);
	return 0;
} 
