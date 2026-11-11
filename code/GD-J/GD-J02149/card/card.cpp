#include <iostream>
#include <cstring>
using namespace std;
int n,m;
int a[500000];
int s[300001];
int r[300001];
bool x[500001];
int main(){
	freopen("card.in","rb",stdin);
	freopen("card.out","wb",stdout);
	cin>>n>>m;
	for(int i=0;i<n;++i) cin>>a[i];
	for(int i=0;i<n;++i){
		memset(s,0xff,sizeof(s));
		memset(x,0,sizeof(x));
		for(int j=i;j<n;++j){
			if(s[a[j]]!=-1){
				if(x[s[a[j]]]){
					s[a[j]]=j;
					continue;
				}
				for(int p=s[a[j]];p<=j;++p)
					x[p]=1;
				s[a[j]]=-1;
			}else s[a[j]]=j;
		}
		for(int j=i;j<n;++j){
			if(x[j]==0)++r[a[j]];
		}
	}
	for(int i=1;i<=m;++i)cout<<r[i]<<' ';
	return 0;
}
