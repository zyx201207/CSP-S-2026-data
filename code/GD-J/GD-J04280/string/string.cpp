#include<iostream> 
#include<string> 
#include<cstdio> 
#define int long long
using namespace std;

int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,l=0,st=0,ed=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	if(l<=1e8){
		int i=1,j=1,ci=c[1],cj=c[n],ii=1,jj=n;
		int ans=0;
		while(st<l/2){
			if(i>a[ii])i=1,ii++;
			if(j>a[jj])j=1,jj--;
			ci=c[ii];
			cj=c[jj];
			if(ci!=cj)ans++;
			i++,j++;
			st++;
		}
		cout<<ans<<endl;
		return 0;
	}
	int i=1,j=1,ci=c[1],cj=c[n],ii=1,jj=n;
	int ans=0;
	while(st<l/2){
		if(i>a[ii])i=1,ii++;
		if(j>a[jj])j=1,jj--;
		ci=c[ii];
		cj=c[jj];
	//	cout<<ii<<" "<<i<<" "<<jj<<" "<<j<<endl; 
		if(a[ii]-i<=a[jj]-j){
			if(ci!=cj)ans+=min(l/2-st,a[ii]-i+1);
	//		cout<<ans<<endl;
			i=a[ii];
			j+=a[ii]-1; 
			st+=a[ii];
		}else{
			if(ci!=cj)ans+=min(l/2-st,a[jj]-j+1);
	//		cout<<ans<<endl;
			j=a[jj];
			i+=a[jj]-1; 
			st+=a[jj];
		}
		i++,j++;
	}
	cout<<ans<<endl;
	return 0;
}

/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/ 
