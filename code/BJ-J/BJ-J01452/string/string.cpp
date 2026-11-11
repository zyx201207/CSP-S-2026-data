#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a;string s;long long b[200005],lin=0,sm=0;char c[200005];
	cin>>a;
	for (long long i=0;i<a;i++){
		string s1;
		cin>>b[lin]>>s1;
		c[lin]=s1[0];
		sm+=b[lin++];
	}long long bth=sm/2;lin--;long long ni=0,nj=0,ci=0,cj=0,ans=0;
	long long i=0,j=lin,ai=0,aj=sm;
	for (i=0,j=lin,ai=0,aj=sm;ai<=bth&&aj>=sm-bth;i=i){
		if (ni>nj){
			if (ci!=cj){
				ans+=nj;
			}ni-=nj;
			nj=b[j];
			cj=c[j];
			aj-=b[j--];
		}else{
			if (ci!=cj){
				ans+=ni;
			}nj-=ni;
			ni=b[i];
			ci=c[i];
			ai+=b[i++];
		}
	
	}
	if (ni>nj){
			if (ci!=cj){
				ans+=nj;
			}ni-=nj;
			nj=b[j];
			cj=c[j];
			aj-=b[j--];
		}else{
			if (ci!=cj){
				ans+=ni;
			}nj-=ni;
			ni=b[i];
			ci=c[i];
			ai+=b[i++];
		}
	
	
	cout<<ans;
	return 0;
}
