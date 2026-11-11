#include<bits/stdc++.h>
using namespace std;
struct node {
bool p[31];
}arr[20000];
int r;
int pp[31];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,sign[20000],o=0,ans=0;
	long long a;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&a);
		while(a>=1){
		int t=0;
		if(a%2)
		{
			arr[i].p[t++]=1;
			
		}
		a/=2;
		r=max(r,t);
		}
	}
	for(int i=r-1;i>=0;i--){
		for(int j=0;j<n;i++){
		if(arr[j].p[i]){
			pp[i]++;
	}
		}
		if(pp[i]>=m){
		    for(int j=0;j<n;i++){
		if(arr[j].p[i]){
			sign[o++]=j;
	}
		}
		break;
	}
}
	for(int i=r-1;i>=0;i--){
		bool fag=1;
		for(int j=0;j<o-1;i++){
		if(!arr[sign[j]].p[i]){
			fag=0;
	}
	if(fag){
		ans+=pow(2,i);
}	}
	}
	cout<<ans;
	return 0;
}
