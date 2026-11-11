#include<cstdio>
#include<vector>
const int MAXN=2e5+5;
int n,m;
int a[MAXN];
std::vector<int> ea;
std::vector<int> eb;
bool op=true;
int cnt;
int ans;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		ea.push_back(i);
	}
	for(int i=30;i>=0;i--){
		cnt=0;
		if(op){
			eb.clear();
			for(int j=0;j<ea.size();j++){
				if((a[ea[j]]>>i)%2==1) eb.push_back(ea[j]);
			}
			if(eb.size()>=m){
				ans+=(1<<i);
				op=false;
			}
		}else{
			ea.clear();
			for(int j=0;j<eb.size();j++){
				if((a[eb[j]]>>i)%2==1) ea.push_back(eb[j]);
			}
			if(ea.size()>=m){
				ans+=(1<<i);
				op=true;
			}
		}
	}
	printf("%d",ans);
	return 0;
}
