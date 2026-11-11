#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int len[N],n;
int ans=0,all_len;
char s[N];
signed main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>len[i]>>s[i];
		all_len+=len[i];
	}
	int llen=0,rlen=0;
	int mid=0;
	for(int i=1;i<=n;i++) {
		if(llen<all_len/2) {llen+=len[i];mid=i;}
		else rlen+=len[i];
	}
	if(llen>rlen) {
		if(llen-len[mid]>rlen) {
			ans+=llen-len[mid]-rlen;
		} else 
		if(llen-len[mid]<rlen){
			ans+=rlen+len[mid]-llen;
		}
		int l=1,r=n;
		llen=len[1],rlen=len[n];
		int isr=2;
		
		while(l<r && l!=mid && r!=mid) {
			if(s[l]!=s[r]) {
				if(llen>rlen && isr==1) ans+=len[r];
				else if(llen>rlen && isr==0) ans+=rlen-llen+len[l];
				else if(rlen>llen && isr==1) ans+=llen-rlen+len[r];
				else if(rlen>llen && isr==0) ans+=len[l];
				else if(isr=2) {
					if(llen>rlen) ans+=len[r];
					else ans+=len[l];
				}
			}
			if(llen>rlen) {rlen+=len[--r];isr=1;}
			else if(rlen>llen) {llen+=len[++l];isr=0;}
			else {rlen+=len[--r];llen+=len[++l];isr=2;}
		}
		
	} else {
		int l=1,r=n;
		llen=len[1],rlen=len[n];
		int isr=2;
		while(l<r) {
			if(s[l]!=s[r]) {
				if(llen>rlen && isr==1) ans+=len[r];
				else if(llen>rlen && isr==0) ans+=rlen-llen+len[l];
				else if(rlen>llen && isr==1) ans+=llen-rlen+len[r];
				else if(rlen>llen && isr==0) ans+=len[l];
				else if(isr=2) {
					if(llen>rlen) ans+=len[r];
					else ans+=len[l];
				}
			}
			if(llen>rlen) {rlen+=len[--r];isr=1;}
			else if(rlen>llen) {llen+=len[++l];isr=0;}
			else {rlen+=len[--r];llen+=len[++l];isr=2;}
		}
	}
	cout<<ans;
	return 0;
} 
