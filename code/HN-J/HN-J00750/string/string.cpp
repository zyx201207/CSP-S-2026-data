#include<bits/stdc++.h>
using namespace std;
long long a,z2,b[2000005],z1,z,t,w;
char c[2000005];
int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>a;
	for(long long i=0;i<a;i++){
		cin>>b[i]>>c[i];
		z+=b[i];
	} 
	w=a-1;
	long long  yb=z/2;
	while(z2<=yb){
		if(c[t] != c[w]){
			if(b[t]>=b[w]){
				z1+=b[w];
				z2+=b[t];
				b[t]-=b[w];
				w--;
				
				if(b[t]==0){
					t++;
				}
			}else{
				z1+=b[t];
				z2+=b[t];
				b[w]-=b[t];
				t++;
			}
		}else{
			if(b[t]>=b[w]){
				b[t]-=b[w];
				w--;
				z2+=b[t];
				if(b[t]==0){
					t++;
				}
			}else{
				b[w]-=b[t];
				z2+=b[t];
				t++;
			}
		}
	}
	cout<<z1;
	return 0;
} 
