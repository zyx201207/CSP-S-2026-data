#include<cstdio>
#include<vector> 
const int MAXN=5e5+5;
const int MAXM=3e5+5;
int n,m;
int a[MAXN];
int d[MAXM];
std::vector<int> e;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		e.clear();
		for(int j=i;j<=n;j++){
			int k=0;
			for(;k<e.size();k++){
				if(e[k]==a[j]) break;
			}
			while(e.size()>k){
				e.pop_back();
			}
			e.push_back(a[j]);
		}
		for(int ii=0;ii<e.size();ii++){
			d[e[ii]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",d[i]);
	}
	return 0;
}
