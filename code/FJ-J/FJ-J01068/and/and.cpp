#include<bits/stdc++.h>
using namespace std;
int n,m,sizeof1[32],maxsize,ans;
struct number{
	int z;
	int j01[32];
	int size;
};
bool cmp(number p,number q){return p.z>q.z;}
void put01(number &a){
	int i=1,m=a.z;
	while(m!=0){
		a.j01[i]=m%2;
		m/=2;
		i++;
	}a.size=i-1;
	return;
}number a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].z;
		put01(a[i]);
		maxsize=max(maxsize,a[i].size);
	}for(int i=maxsize;i>=1;i--){
		for(int j=1;j<=n;j++){
			sizeof1[i]+=a[j].j01[i];
		}
	}for(int i=maxsize;i>=1;i--){
		if(sizeof1[i]<m){
			for(int j=1;j<=n;j++){
				if(a[j].j01[i]){
					a[j].z-=(1<<(i-1));
				}
			}
		}else break;
	}sort(a+1,a+n+1,cmp);
	ans=a[1].z;
	for(int i=2;i<=m;i++){
		ans=ans&a[i].z;
	}cout<<ans;
	return 0;
}
