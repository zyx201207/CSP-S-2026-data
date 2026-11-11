#include<bits/stdc++.h>
using namespace std;
long long a,b[200007],c=0,d,e,i=0,j=0,r=0,l=0,q,w,ans=0;
char o[200007];
struct xy{
	long long n;
	char m;
}v[200007],t[200007],rt,po;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long long x=1;x<=a;x++){
		cin>>b[x]>>o[x];
		c+=b[x];
	}
	if(c%2==1){
		d=c/2;
		bool p=0;
		for(long long x=1;x<=a;x++){
			e+=b[x];
			if(e==d){
				i++;
				v[i].n=b[x];
				v[i].m=o[x];
				w=x;
				break;
			}else if(e>d){
				i++;
				v[i].n=d-q;
				v[i].m=o[x];
				if(e>d+1){
					j++;
					t[j].n=e-(d+1);
					t[j].m=o[x];
				}
				w=x;
				break;
			}
			i++;
			v[i].n=b[x];
			v[i].m=o[x];
			q=e;
		}
		for(long long x=w+1;x<=a;x++){
			j++;
			t[j].n=b[x];
			t[j].m=o[x];
		}
		r=i;
		l=1;
		rt=v[r];
		po=t[l];
		while(1){
			if(l>j || r<=0){
				break;
			}
			if(rt.n>po.n){
				if(rt.m!=po.m){
					ans+=po.n;
				}
				rt.n-=po.n;
				l++;
				po=t[l];
			}else if(po.n>rt.n){
				if(rt.m!=po.m){
					ans+=rt.n;
				}
				po.n-=rt.n;
				r--;
				rt=v[r];
			}else if(po.n==rt.n){
				if(rt.m!=po.m){
					ans+=rt.n;
				}
				r--;
				rt=v[r];
				l++;
				po=t[l];
			}
		}
		cout<<ans;
	}else if(c%2==0){
		d=c/2;
		bool p=0;
		for(long long x=1;x<=a;x++){
			e+=b[x];
			if(e==d){
				i++;
				v[i].n=b[x];
				v[i].m=o[x];
				w=x;
				break;
			}else if(e>d){
				i++;
				v[i].n=d-q;
				v[i].m=o[x];
				if(e>d){
					j++;
					t[j].n=e-d;
					t[j].m=o[x];
				}
				w=x;
				break;
			}
			i++;
			v[i].n=b[x];
			v[i].m=o[x];
			q=e;
		}
		for(long long x=w+1;x<=a;x++){
			j++;
			t[j].n=b[x];
			t[j].m=o[x];
		}
		r=i;
		l=1;
		rt=v[r];
		po=t[l];
		while(1){
			if(l>j || r<=0){
				break;
			}
			if(rt.n>po.n){
				if(rt.m!=po.m){
					ans+=po.n;
				}
				rt.n-=po.n;
				l++;
				po=t[l];
			}else if(po.n>rt.n){
				if(rt.m!=po.m){
					ans+=rt.n;
				}
				po.n-=rt.n;
				r--;
				rt=v[r];
			}else if(po.n==rt.n){
				if(rt.m!=po.m){
					ans+=rt.n;
				}
				r--;
				rt=v[r];
				l++;
				po=t[l];
			}
		}
		cout<<ans;
	}
	return 0;
} 
