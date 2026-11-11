#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
int n; 
char c[MAXN];
unsigned long long siz,bg[MAXN],a[MAXN];
int find(int x){
	int i=1;
	while(x>bg[i]){
		i++;
	}
	i--;
	return i;
}
int main(){
	freopen("string.in","r",stdin);//!!!
	freopen("string.out","w",stdout);//!!!
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		siz+=a[i];
		bg[i]=bg[i-1]+a[i-1];
	}
	bg[n+1]=bg[n]+a[n];
	unsigned long long fi=1,ed=siz;
	int ans=0;
	unsigned long long cen1=find(n/2+1);
	while(fi<=ed){
		//cout<<"fi: "<<fi<<" ed: "<<ed<<" "<<"findfi: "<<find(fi)<<" finded: "<<find(ed)<<endl;
		int ff=find(fi),ef=find(ed);
		//int minx=min(a[ff],a[ef]);
		//cout<<minx<<endl;
		if(c[ff]!=c[ef]){
			/*if(n&2==1 and (ff==cen1 or ef==cen1)){
				ans--;
			}
			ans+=minx;*/
			ans++;
		}
		
		//fi+=minx; ed=siz+1-fi;
		
		fi++;ed--;
		
	}
	cout<<ans;
	return 0;
} 
