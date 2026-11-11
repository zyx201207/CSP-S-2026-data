#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll ans,len,n;
int a[200009];
char c[200009];
int main(){
	freopen("string.in","r",stdin);	
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d %c",&a[i],&c[i]);
		len+=a[i];
	}
	ll l=0,r=n-1,llen=0,rlen=0;
	llen=a[l],rlen=a[r];
	while(l<=r){
		if(llen==0){
			l++;
			llen=a[l];
		}
		if(rlen==0){
			r--;
			rlen=a[r];
		}
		if(llen>rlen){
			if(c[l]!=c[r])ans+=rlen;
			llen-=rlen;
			r--;
			rlen=a[r];
		}else{
			if(c[l]!=c[r])ans+=llen;
			rlen-=llen;
			l++;
			llen=a[l];
		}
		
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
