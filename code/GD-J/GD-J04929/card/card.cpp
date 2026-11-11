#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],mi[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	map<int,int> p;
	vector<int> ans;
	for(int i=1;i<=n;i++){
		p.clear();
		ans.clear();
		for(int j=i;j<=n;j++){
			if(p[a[j]]!=0){
				int start;
				for(int y=0;y<ans.size();y++)
					if(ans[y]==a[j])
						start=y;
				for(int y=start;y<ans.size();y++)
					p[ans[y]]=0;			
				ans.push_back(a[j]);
				p[a[j]]=1;
			}
			else{
				ans.push_back(a[j]);
				p[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(p[j]){
				mi[j]++;
				p[j]=0;
			}
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",mi[i]);
	return 0;
}
