#include <iostream>
#include <cstdio>

#define N 200005

using namespace std;

int n,a[N],suma[N],sumfza[N];
long long sum=0;
char s[N];

int fza[N];
char fzs[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>s[i];
	for(int i=1;i<=n;i++) fza[n-i+1]=a[i];
	for(int i=1;i<=n;i++) fzs[n-i+1]=s[i];
	for(int i=1;i<=n;i++) suma[i]=suma[i-1]+a[i];
	for(int i=1;i<=n;i++) sumfza[i]=sumfza[i-1]+fza[i];
	
	//for(int i=1;i<=n;i++) cout<<fza[i]<<' ';
	//cout<<'\n';
	
	int l=1,r=1;
	while(l<=n&&r<=n){
		int ansa=suma[l],ansfza=sumfza[r];
		//cout<<l<<' '<<r<<' '<<sum<<' '<<ansa<<' '<<ansfza<<'\n';
		if(ansfza<ansa){
			int len=(sumfza[r]-(suma[l-1]+1)+1);
			if(sumfza[r-1]+1>suma[l-1]+1) len=sumfza[r]-(sumfza[r-1]+1)+1;
			if(s[l]!=fzs[r]) sum+=len;
			r++;
			//cout<<"_1";
		}
		else if(ansfza>ansa){
			int len=(suma[l]-(sumfza[r-1]+1)+1);
			if(sumfza[r-1]+1<suma[l-1]+1) len=suma[l]-(suma[l-1]+1)+1;
			if(s[l]!=fzs[r]) sum+=len;
			l++;
			//cout<<"_2";
		}
		else{
			int len=(suma[l]-max(suma[l-1]+1,sumfza[r-1]+1)+1);
			if(s[l]!=fzs[r]) sum+=len;
			l++,r++; 
			//cout<<"_3";
		}
	}
	//cout<<l<<' '<<r<<' '<<sum<<' '<<ans<<'\n';
	cout<<sum/2;
	return 0;
} 
