#include<bits/stdc++.h>
using namespace std;
long long n,m;
const long long N=5e5+5;
long long a[N],zhm[N];
int main(){
	//freopen("card.in","w",stdin);
	//freopen("card.out","r",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	long long i=1;
	while(i<=n){
		long long t[N]={0},now[N]={0},la[N]={0};
		long long wz=1;
		for(int j=i;j<=n;j++){
			if(t[a[j]]){
				for(long long k=la[a[j]];k<=n;k++){
					t[now[k]]=0;
					now[k]=0;
				}
				if(1==la[a[j]]) wz=1;
				else wz=la[a[j]];
				now[wz]=a[j];
				t[now[wz]]++;
				wz++;
			}else{
				now[wz]=a[j];
				t[now[wz]]++;
				la[now[wz]]=j;
				wz++;
			}
		}
		for(long long j=1;j<=m;j++){
			if(t[j]){
				zhm[j]++;
			}
		}
		i++;
	}
	for(long long j=1;j<=m;j++){
			cout<<zhm[j]<<" ";
		}
	return 0;
}

