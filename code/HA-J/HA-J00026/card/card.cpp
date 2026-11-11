#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m;
int a[N];
int ans[M];
int desk[N];
int p[M];
int t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	    cin>>a[i];
	for(int i=1;i<=n;i++){
		t=1;
		for(int j=1;j<=m;j++) p[j]=-1;
		for(int j=i;j<=n;j++){
			if(p[a[j]]!=-1){
				for(int k=p[a[j]]+1;k<t;k++)
				    p[a[k]]=-1;
				t=p[a[j]];
				p[a[j]]=-1;
			}
			desk[t]=a[j];
			p[a[j]]=t;
			t++;
		}
		for(int j=1;j<t;j++)
			ans[desk[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
