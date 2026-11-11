#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],sum=0,ans=0,anss=-1,maxx=-0x3f3f3f3f3f3f3f3f,l;
bool cmp(int x,int y){return l-x<l-y;}
int main(){
	freopen("w","crystal.in",stdin);
	freopen("r","crystal.out",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){cin>>a[i];sum+=a[i];maxx=max(a[i],maxx);}sum/=n;
	for(long long l=sum;l<=maxx+m;l++){
		long long mm=m;
		sort(a,a+n,cmp);
		for(long long i=0;i<n;i++){
			if(a[i]<=l and mm-l+a[i]>=0){mm-=l-a[i];ans++;}
			else if(mm-l+a[i]==0){mm-=l-a[i];ans++;break;}
		}
		anss=max(ans,anss);ans=0;
		if(anss==n){break;} 
	}
	if(anss<=0){anss=1;}
	cout<<anss;
	return 0;
}
