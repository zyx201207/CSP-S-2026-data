#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long p=1,num=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-')p=-p;
		c=getchar();
	}
	while(isdigit(c)){
		num=num*10+c-'0';
		c=getchar();
	}
	return num*p;
}
long long n,m,a[500010];
inline long long f(int num){
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=max(0LL,num-a[i]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long minn=LLONG_MAX;
	n=read();m=read();
	for(long long i=1;i<=n;i++){
		a[i]=read();
		minn=min(minn,a[i]);
	}
	int num=minn;
	for(;f(num+1000000000000000000)<=m;num+=1000000000000000000);
	for(int i=num;num-i<=1000000000000000000;num+=100000000000000000){
		if(f(num+100000000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=100000000000000000;num+=10000000000000000){
		if(f(num+10000000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=10000000000000000;num+=1000000000000000){
		if(f(num+1000000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=1000000000000000;num+=100000000000000){
		if(f(num+100000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=100000000000000;num+=10000000000000){
		if(f(num+10000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=10000000000000;num+=1000000000000){
		if(f(num+1000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=1000000000000;num+=100000000000){
		if(f(num+1000000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=1000000000000;num+=100000000000){
		if(f(num+100000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=100000000000;num+=10000000000){
		if(f(num+10000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=10000000000;num+=1000000000){
		if(f(num+1000000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=1000000000;num+=100000000){
		if(f(num+100000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=100000000;num+=10000000){
		if(f(num+10000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=10000000;num+=1000000){
		if(f(num+1000000)>m){
			break;
		}
	}
	for(int i=num;num-i<=1000000;num+=100000){
		if(f(num+100000)>m){
			break;
		}
	}
	for(int i=num;num-i<=100000;num+=10000){
		if(f(num+10000)>m){
			break;
		}
	}
	for(int i=num;num-i<=10000;num+=1000){
		if(f(num+1000)>m){
			break;
		}
	}
	for(int i=num;num-i<=1000;num+=100){
		if(f(num+100)>m){
			break;
		}
	}
	for(int i=num;num-i<=100;num+=10){
		if(f(num+10)>m){
			break;
		}
	}
	for(int i=num;num-i<=10;num+=1){
		if(f(num+1)>m){
			break;
		}
	}
//	cout<<num<<' '<<f(num)<<' '<<f(num+1)<<'\n';
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]<=num)ans++;
	}
	cout<<ans<<'\n';
	return 0;
}
