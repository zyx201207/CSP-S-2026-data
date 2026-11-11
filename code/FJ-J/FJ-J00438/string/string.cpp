#include <bits/stdc++.h>
using namespace std;

long long N;
struct p{
	long long a;
	char b;
};
p ps[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>N;
	for(int i=1;i<=N;i++){
		cin>>ps[i].a>>ps[i].b;
	}
	long long n=1,m=N,cnt=0; 
	while(n!=m){
		if(ps[n].b==ps[m].b){
			if(ps[n].a==ps[m].a){
				n++;
				m--;
				if(n-m==1){
					cout<<cnt;
					return 0;
				}
			}else{
				if(ps[n].a>ps[m].a){
					ps[n].a-=ps[m].a;
					m--;
				}else{
					ps[m].a-=ps[n].a;
					n++;
				}
			}
		}else{
			if(ps[n].a==ps[m].a){
				cnt+=ps[n].a;
				n++;
				m--;
				if(n-m==1){
					cout<<cnt;
					return 0;
				}
			}else{
				if(ps[n].a>ps[m].a){
					cnt+=ps[m].a;
					ps[n].a-=ps[m].a;
					m--;
					
				}else{
					cnt+=ps[n].a;
					ps[m].a-=ps[n].a;
					n++;
				}
			}
		}
	}cout<<cnt;
	return 0;
	
}
