#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN],ans[MAXN],sum[MAXN];
stack<int > d;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>ans[i];
	
	memset(sum,0,sizeof(sum));
	
	for(int h=1;h<=m;h++){
		for(int i=max(h-1,1);i<=n;i++){
			if(d.empty()) d.push(a[i]);
			else{
				bool flag=false;
				for(int j=1;j<=d.size();j++){
					if(a[i]==d[j]) ;
				}
			}
		}
	}
	
	
	
	for(int i=1;i<=m;i++) cout<<sum[ans[i]]<<' ';
	
	putchar('\n');
	return 0;
}
