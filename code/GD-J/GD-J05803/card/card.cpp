#include<bits/stdc++.h>
using namespace std;
long long d[1000000000000],p[1000000000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long a,b,cnt=0;
	cin>>a>>b;
	long long c[a];
	for(long long i=0;i<a;i++){
		cin>>c[i];
	}
	for(long long i=0;i<a;i++){
		cnt=0;
		for(long long j=i;j<a;j++){
			d[cnt]=c[j];
			for(long long k=0;k<cnt;k++){
				if(d[k]==c[j]){
					for(long long f=0;f<cnt;f++){
						if(d[f]==c[j]){
							cnt=f;
							break;
						}
					}
				}
			}
			cnt++;	
		}
		for(long long j=0;j<cnt;j++){
			p[d[j]]++;
		}
		for(long long j=0;j<1000000000;j++){
			d[i]=0;
		}
	}
	for(long long i=1;i<b+1;i++){
		cout<<p[i]<<' ';
	}
	return 0;
}













































