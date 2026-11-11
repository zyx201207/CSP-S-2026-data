#include<iostream>
#include<algorithm>
#include<cmath>
#define int long long
using namespace std;
const int MAXN=2e6+5;
int a[MAXN];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
 
    for(int i=1;i<=n;i++){
    	cin>>a[i];
	}
	
	sort(a+1,a+1+n,cmp);
	int maxx;
	for(int i=1;i<=n-m+1;i++){
		bool flag=false;
		maxx=a[i];
		int k=i+m-1;
		for(int j=i+1;j<=k;j++){
			if((maxx & a[j])==0){
				k++;
				if(k>n) break;
				continue;
			}
			maxx&=a[j];
			flag=true;
		}
		if(flag) break;
	}
	cout<<maxx<<endl;
	return 0;
} 
