#include<bits/stdc++.h>
using namespace std;

long long a[800000];

struct Num{
	long long id;
	long long num;
}aa[1000005];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int N=1;
	for(int i=1;i<=n;i++){
		if(i==1){
			aa[N].id=a[1];
			aa[N].num++;
			continue;
		}
		if(a[i]!=a[i-1]){
			N++;
			//cout<<N;
			aa[N].id=a[i];
			aa[N].num++;
			
			continue;
		}
		aa[N].num++;
	}
//	for(int i=1;i<=N;i++){
//		cout<<aa[i].id<<' '<<aa[i].num<<'\n';
//	}	
	long long ans=0;
	for(int i=1;i<=N;i++){
		//	cout<<'1';
		long long cnt=0;
		int now=i-1;
		long long ans1=aa[i].num;
		while(now>0&&cnt<m){
			//cout<<now<<' ';
			long long cha=aa[i].id-aa[now].id;
			if(cha*aa[now].num+cnt<m){
				
				cnt+=cha*aa[now].num;
				ans1+=aa[now].num;
				now--;
			}else{
				
				long long c=floor(1.0*(m-cnt)/cha);
				ans1+=c;
				now--;
				break;
			}
		}
		ans=max(ans1,ans);
	}
	cout<<ans;
} 
/*
5 8
-3 -1 2 2 7


*/ 
