#include<bits/stdc++.h>
using namespace std;
int b[500005];
struct node{
	int z,ls,flag,ans;
}a[300005];
bool cmp(node x,node y){
	return x.ls>y.ls;
}
bool cmp1(node x,node y){
	return x.z<y.z;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[i];
		a[b[i]].z=b[i];
		a[b[i]].flag++;
		a[b[i]].ls=i;
	} 
	sort(a+1,a+m+1,cmp);
	int l=1;
	for(int i=1;i<=m;i++){
		if(a[i].flag!=1){
			l=i;
			i=m+1;
		}
	}
	for(int i=1;i<=n;i++){
		if(l==-1){
			for(int j=i;j<=n;j++){
				a[b[j]].ans++;
			}
		}else{
			for(int j=1;j<=m;j++){
				if(a[j].ls>=a[l].ls){
					a[j].ans++;
				}
			}
			a[l].flag--;
			bool f=1;
			for(int j=l;j<=m;j++){
				if(a[j].flag!=1){
					l=j;
					j=m+1;
					f=0;
				}
			}
			if(f==1)l=-1;
			sort(a+1,a+m+1,cmp1);
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i].ans<<" ";
	return 0;
}
