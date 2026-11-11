#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5,M=3e5+5;

int a[N],cnt[M]={0};

int n,m;

int find(int x,int l,int a[]){
	for(int i=1;i<=l;i++){
		if(a[i]==x)
			return i;
	}
	return l+1;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int s[N]={0};
		int l=0;
		for(int j=i;j<=n;j++){
			int x=find(a[j],l,s);
			if(x==l+1){
				l++;
				s[l]=a[j];
			}else{
				s[x+1]=0;
				l=x;
			}
		}
		
		for(int j=1;j<=l;j++){
			cnt[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",cnt[i]);
	}
	return 0;
}