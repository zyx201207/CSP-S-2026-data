#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n;
int a[N],ans=0;
char ch[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
	}
	int l=1,r=n,numl=a[1],numr=a[n];
	while(l<r){
		if(ch[l]==ch[r]){
			if(numl>numr){
				r--;
				numl-=numr;
				numr=a[r];
			}else if(numl<numr){
				l++;
				numr-=numl;
				numl=a[l];
			}else{
				l++,r--;
				numr=a[r];
				if(l!=r) numl=a[l];
			}
		}else{
			if(numl>numr){
				r--;
				ans+=numr;
				numl-=numr;
				numr=a[r];
			}else if(numl<numr){
				l++;
				ans+=numl;
				numr-=numl;
				numl=a[l];
			}else{
				l++,r--;
				ans+=numr;
				numr=a[r];
				if(l!=r) numl=a[l];
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
