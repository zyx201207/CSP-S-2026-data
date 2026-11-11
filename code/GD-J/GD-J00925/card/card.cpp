#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int v[500005];
map<int,int> t;//¿¨-Î» 
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=0;
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				for(int k=t[a[j]]+1;k<=s;k++){
					t[v[k]]=0;
					v[k]=0;
				}
				s=t[a[j]];
			}else{
				v[++s]=a[j];
				t[a[j]]=s;
			}
		}
		for(int i=1;i<=s;i++){
			ans[v[i]]++;
			cout<<v[i]<<" ";
		}
		cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
