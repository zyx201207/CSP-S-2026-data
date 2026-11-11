#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll l001[300000][3],l005[300000][3],l007[300000],l011[300000][3],l015[300000][3];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,tmp1,ans=0,nn=0;
	char tmp3;
	cin>>n;
	/*
	ll l5s=0,l7s=0;
	for(ll i=0;i<n;i++){
		scanf("%d %c",&tmp1,&tmp3);
		l001[i][0]=nn;l001[i][2]=int(tmp3);
		nn+=tmp1;
		l001[i][1]=nn;
	}
	for(int i=0;i<n;i++){
		if(l001[i][0]>=nn/2){
			l005[l5s][0]=nn-l001[i][1];
			l005[l5s][1]=nn-l001[i][0];
			l5s++;
		}
		if(l001[i][0]<nn/2 && l001[i][1]>=nn/2){
			l005[l5s][0]=l001[i][0];
			l005[l5s][1]=nn/2;
			l001[i][1]=nn/2;
		}
	}
	for(int i=0;i<=n;i++){
		if(i<l5s){
			l007[l7s++]=l005[i][0];
		}
		if(l001[i][0]<=nn/2){
			l007[l7s++]=l001[i][0];
		}
		l007[l7s++]=nn/2;
	}
	ll l11s=0,l15s=0;
	sort(l007,l007+l7s);
	for(int i=0;i<l7s;i++){
		for(int h=0;h<n;h++){
			if(l001[h][0]<=l007[i] && l001[h][1]>l007[i]){
				l011[l11s][0]=l007[i];
				l011[l11s][1]=l007[i+1];
				l011[l11s++][2]=l001[h][2];
				break;
			}
		}
		for(int h=0;h<n;h++){
			if(l005[h][0]<=l007[i] && l005[h][1]>l007[i]){
				l015[l15s][0]=l007[i];
				l015[l15s][1]=l007[i+1];
				l015[l15s++][2]=l005[h][2];
				break;
			}
		}
	}
	for(int i=0;i<l11s && i<l15s;i++){
		if(l011[i][2]!=l015[i][2]){
			ans+=l011[i][1]-l015[i][0];
		}
	}
	//*/
	//*
	ll gc=-1;
	for(ll i=0;i<n;i++){
		scanf("%d %c",&tmp1,&tmp3);
		l001[i][0]=nn;l001[i][2]=int(tmp3);
		nn+=tmp1;
		l001[i][1]=nn;
		if(gc==-1) gc=tmp1;
		else gc=__gcd(gc,tmp1);
	}
	gc=__gcd(gc,nn);
	ll j,a,b;
	for(ll i=0;i<nn/2;i+=gc){
		j=nn-i-1;
		for(int h=0;h<n;h++){
			if(l001[h][0]<=i && l001[h][1]>i){
				a=l001[h][2];
			}
		}
		for(int h=n-1;h>=0;h--){
			if(l001[h][0]<=j && l001[h][1]>j){
				b=l001[h][2];
			}
		}
		if(a!=b) ans+=gc;
	}
	//*/
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

