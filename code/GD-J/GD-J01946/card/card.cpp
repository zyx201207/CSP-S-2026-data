#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	scanf("%d%d",&n,&m);
	vector<int> a(n+1),ans(m+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=1;i<=n;i++){
		int l=0;
		vector<int> c(n+1,0);
		for(int j=i;j<=n;j++){
			int idx=find(c.begin(),c.begin()+l+1,a[j])-c.begin();
			 
			if(idx>=l||idx<=0){
				c[++l]=a[j];
			}
			else{
				l-=(l-idx);
			}
		}
		for(int j=1;j<=l;j++){
			ans[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	
	return 0;
}


