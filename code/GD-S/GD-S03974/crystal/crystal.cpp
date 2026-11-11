#include<iostream> // ¶þ·Ö 
#include<algorithm> 
#include<cmath> 
#define int long long
using namespace std;
const int MAXN=5e5+5;
int a[MAXN];
int n,m,t,d;

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t=max(t,a[i]);
		d=min(d,a[i]);
	}
	sort(a+1,a+n+1,cmp);
	int maxx=0,x=1;
    for(int i=d;i<=t;i++){
    	int sum=0;
    	
    	if((i-d)*n>=1e9-4e8) break;
    	int have=m;
    	
    	for(int j=1;j<=n;j++){
    		int need=abs(i-a[j]);
    		if(have>=need && i>=a[j]){
    			have-=need;
    			sum++;
			} 
		}
		if(maxx<sum){
			maxx=sum;
		}
	}
	cout<<maxx<<endl;
	return 0;
}
