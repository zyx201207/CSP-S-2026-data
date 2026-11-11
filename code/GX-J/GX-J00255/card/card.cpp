#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000000];
struct shu{
	bool vis=true;
	int pos=0;
	int front=0;
	int ans=0;
};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int l=n;
	shu num[m+5];
	while(n--){
		for(int i=1;i<=l;++i){
			num[a[i]].pos++;
			if(num[a[i]].vis){
				num[a[i]].front=i;
				num[a[i]].vis=false;
			}
			if(num[a[i]].pos==2){
				for(int j=num[a[i]].front;j<i;++j)a[j]=0;
				num[a[i]].pos=1;
				num[a[i]].front=i;
			}
		}
		int temp=l;
		for(int j=2;j<=l;++j){
			if(a[j]!=0){
				while(a[j-1]==0){
					temp--;
					a[j-1]=a[j];
					a[j]=0;
				}
				num[a[j]].ans++;
			}
		}
		l=temp;
	}
	for(int i=1;i<=m;++i)printf("%d ",num[i].ans);
}
