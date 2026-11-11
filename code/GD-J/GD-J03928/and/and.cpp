#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5;

int n,m;
int num[N];
int maxx;
map<int,int> mp;
void init(){
	for(int i=0;i<=22;i++){
		int x=pow(2,i);
		mp[x]=i+1;
	}
}

int lb(int x){
	return x&(-x);
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	init();
//	cout<<lb(int(pow(2,20)))<<" ";
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		maxx=max(maxx,num[i]);
	} 
	
	if(n<=20){
		int l=pow(2,n);
		maxx=0;
	
		for(int i=1;i<=l;i++){	
			int cnt=0,sum=0,f=0,t=i;
			while(true){
				int p=mp[lb(t)];
				if(p==l) break;
				if(cnt==m){
					maxx=max(maxx,sum);
					break;
				} 
				if(!f) sum=num[p],f=1;
				else sum&=num[p];
				cnt++;t-=lb(t);
			}
		} 
		cout<<maxx;
	}else{
		if(m==1) cout<<maxx;
		if(m==2){
			maxx=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					maxx=max(maxx,(num[i]&num[j]));
				}
			}
			cout<<maxx;
		}else{
			if(maxx<=4){
				sort(num+1,num+1+n);
				int sum=num[1],cnt=0;
				for(int i=2;i<=n;i++){
					if(num[i]&sum>sum) sum&=num[i],cnt++;
					if(cnt==m) break;
				}
				cout<<sum;
			}else{
				int  l=pow(2,n);
				maxx=0;
	
				for(int i=1;i<=l;i++){	
					int cnt=0,sum=0,f=0,t=i;
					while(true){
						long long p=mp[lb(t)];
						if(p==l) break;
						if(cnt==m){
							maxx=max(maxx,sum);
							break;
						} 
						if(!f) sum=num[p],f=1;
						else sum&=num[p];
						cnt++;t-=lb(t);
					}
				} 
				cout<<maxx;
			}
		}
	}
	return 0;
}

