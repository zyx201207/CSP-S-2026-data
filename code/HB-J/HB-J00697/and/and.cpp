#include<bits/stdc++.h>
using namespace std;
long long all[100];
long long N=1;
long long n,m;
struct node{
	long long num;
	long long t;
	long long w[100];
	long long z;
};
struct kfc{
	long long o;
	long long s;
};
long long maxx=0;
node k[200020];
void power(long long x,long long num,long long q,long long cnt){
	if(num>=q){
		num=num%q;
		k[x].w[cnt]++;
		all[cnt]++;
		maxx=max(maxx,cnt);
		k[x].z+=cnt;
	}
	q/=2;
	cnt--;
	if(cnt==0||num==0){
		return;
	}else{
		power(x,num,q,cnt);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	for(int i=1;i<=31;i++){
		N*=2;
	}
	cin >> n >> m;
	for(long long i=1;i<=n;i++){
		cin >> k[i].num;
		k[i].t=k[i].num;
		power(i,k[i].t,N,32);
	}
	while(all[maxx]<m&&maxx>0){
		maxx--;
	}
	if(maxx<=0){
		cout << 0;
		return 0;
	}
	kfc c[200020]={};
	for(int i=1;i<=n;i++){
		if(k[i].w[maxx]==1){
			c[k[i].z].o=k[i].num;
			c[k[i].z].s++;
		}
	}
	long long cnt=0;
	long long p[200020]={};
	for(int i=10000;i>=0;i--){
		if(c[i].o>0){
			for(int j=c[i].s;j>0;j--){
				cnt++;
				p[cnt]=c[i].o;
			}
		}
	}
	long long ans=p[1];
	m--;
	for(int i=2;i<=cnt;i++){
		if(m==0){
			break;
		}
		ans=ans&p[i];
		m--;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
