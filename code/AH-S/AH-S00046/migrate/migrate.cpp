#include<bits/stdc++.h>
using namespace std;
const int N=1e6+1;
int island[N];
pair<int,int> road[N];//zuixiaolu,shuliang
/*auto*/long long read(){
	char c=getchar_unlocked();
	/*auto*/long long sum=0;
	int f=1;
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar_unlocked();
	}
	while(c>='0'&&c<='9'){
		sum*=10;
		sum+=c-'0';
		c=getchar_unlocked();
	}
	return sum*f;
}
void write(/*auto*/long long sum){
	int s=-1;
	char c[20];
	if(sum<0){
		sum=-sum;
		putchar_unlocked('-');
	}
	if(sum==0){
		putchar_unlocked('0');
		return ;
	}
	while(sum!=0){
		c[++s]=sum%10+'0';
		sum/=10;
	}
	for(int i=s;i>=0;i--) putchar_unlocked(c[i]);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c=read();
	int t=read();
	while(t--){
		int n=read(),d=read();
		for(int i=1;i<=n;i++){
			island[i]=read();
		}
		int sum=0;
		for(int i=1;i<n-1;i++){
			for(int j=i+2;j<=n;j++){
				for(int k=1;k<=n;k++){
					road[k].first=INT_MAX;
					road[k].second=0;
				}
				road[i].first=0;
				for(int k=i;k<=j;k++){
					int cnt=1;
					if(road[k].second==0&&k!=i) continue;
					while(island[k+cnt]-island[k]<=d&&k+cnt<=j){
						if(road[k+cnt].first==road[k].first+1){
							road[k+cnt].second++;
						}
						if(road[k+cnt].first>road[k].first+1){
							road[k+cnt].first=road[k].first+1;
							road[k+cnt].second=1;
						}
						cnt++;
					}
				}
				if(road[j].second==2) sum++;
			}
		}
		write(sum);
		putchar_unlocked('\n');
	}
	return 0;
}
