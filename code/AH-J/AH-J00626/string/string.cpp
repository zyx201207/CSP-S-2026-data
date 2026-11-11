#include<bits/stdc++.h>
using namespace std;
long long n,cnt,x,y,ans;
char c;
//long long n,cnt,x[10000],y,ans;
//char c[10000];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		for(int j=1;j<=x;j++){
			s+=c;
		}
	}
	int sl=s.size();
	for(int i=0;i<sl;i++){
		if(s[i]!=s[sl-i])ans++;
	}/*
	for(int i=1;i<=n;i++){
		cin>>x[i]>>c[i];
		cnt+=x[i];
	}
	long long lw=1,rw=cnt,ls=1,rs=n,posl=0,posr=0;
	while(lw<rw){
			if(posl||posr){
				if(posl){
					long long sa=x[ls]-posl;
					if(sa==x[rs]){
					if(c[ls]!=c[rs]){
					ans+=sa;
					ls++,rs--;
					lw+=sa;
					rw-=sa;
					posl=0,posr=0;
					}else{
					ls++,rs--;
					lw+=sa;
					rw-=sa;
					posl=0,posr=0;
					}
				}
					else{
					if(c[ls]!=c[rs]){
					long long y=min(sa,x[rs]);
					if(sa>x[rs]){posl=x[rs];posr=0;rs--;}
					if(sa<x[rs]){posr=sa;posl=0;ls++;}
					ans+=y;
					lw+=y;
					rw-=y;
					}
					else{
					int y=min(sa,x[rs]);
					if(sa>x[rs]){posl=x[rs];posr=0;rs--;}
					if(sa<x[rs]){posr=sa;posl=0;ls++;}
					lw+=y;
					rw-=y;
					}
				}
				if(c[ls]!=c[rs]){
				ans+=sa;
				ls++,rs--;
				lw+=sa;
				rw-=sa;
				posl=0,posr=0;
				}else{
				ls++,rs--;
				lw+=sa;
				rw-=sa;
				posl=0,posr=0;
				}
			}
				else if(posr){
					long long sa=x[rs]-posr;
					if(sa==x[ls]){
					if(c[ls]!=c[rs]){
					ans+=x[ls];
					ls++,rs--;
					lw+=sa;
					rw-=sa;
					posl=0,posr=0;
					}else{
					ls++,rs--;
					lw+=sa;
					rw-=sa;
					posl=0,posr=0;
					}
				}
					else{
					if(c[ls]!=c[rs]){
					long long y=min(sa,x[ls]);
					if(sa>x[ls]){posr=x[ls];posl=0;ls++;}
					if(sa<x[ls]){posl=sa;posr=0;rs--;}
					ans+=y;
					lw+=y;
					rw-=y;
					}
					else{
					long long y=min(sa,x[ls]);
					if(sa>x[ls]){posr=x[ls];posl=0;ls++;}
					if(sa<x[ls]){posl=sa;posr=0;rs--;}
					lw+=y;
					rw-=y;
					}
				}
				if(c[ls]!=c[rs]){
				ans+=sa;
				ls++,rs--;
				lw+=sa;
				rw-=sa;
				posl=0,posr=0;
				}else{
				ls++,rs--;
				lw+=sa;
				rw-=sa;
				posl=0,posr=0;
				}
			}
			}
		else if(x[ls]==x[rs]){
			if(c[ls]!=c[rs]){
				ans+=x[ls];
				ls++,rs--;
				lw+=x[ls];
				rw-=x[rs];
				posl=0,posr=0;
			}else{
				ls++,rs--;
				lw+=x[ls];
				rw-=x[rs];
				posl=0,posr=0;
			}
		}
		else{
			if(c[ls]!=c[rs]){
				int y=min(x[ls],x[rs]);
				if(x[ls]>x[rs]){posl=x[rs];posr=0;rs--;}
				if(x[ls]<x[rs]){posr=x[ls];posl=0;ls++;}
				ans+=y;
				lw+=y;
				rw-=y;
			}
			else{
				int y=min(x[ls],x[rs]);
				if(x[ls]>x[rs]){posl=x[rs];posr=0;rs--;}
				if(x[ls]<x[rs]){posr=x[ls];posl=0;ls++;}
				lw+=y;
				rw-=y;
			}
		}
	}*/
	cout<<(ans);
	return 0;
}
