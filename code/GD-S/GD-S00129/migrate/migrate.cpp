#include<iostream>
#include<cstdio>
#include<cstring>

long long d;
long long min_len;
long long Sum;

int x[2000010];

long long vis1[2000010];

void DFS1(int A,int B){//求最短路径长度
    if(A==B){
    	vis1[A]=0;
    	return;
	}
	for(int i=A+1;i<=B;++i){
		if(i!=A+1&&vis1[i]-vis1[A]>d){
			break;
		}
		
		if(vis1[i]==-1){
			DFS1(i,B);
		}
		if(vis1[A]==-1){
			vis1[A]=vis1[i]+1;
		}else vis1[A]=std::min(vis1[A],vis1[i]+1);
	}
}

void DFS2(int A,int B,long long sum){//从A出发有多少种方法用最小速度到达B
    if(sum>min_len)return;
    if(A==B){
    	if(sum==min_len){
    		++Sum;
		}
		return;
	}
	
	for(int i=A+1;i<=B;++i){
		if(i!=A+1&&x[i]-x[A]>d)break;
		
		DFS2(i,B,sum+1);
	}
}

int main(){
    freopen("migrate","r",stdin);
    freopen("migrate","w",stdout);
	
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int fw,T;
	std::cin>>fw>>T;
	
	for( ;T>0;--T){
		int n;
		std::cin>>n>>d;
		for(int i=1;i<=n;++i){
			std::cin>>x[i];
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				memset(vis1,-1,sizeof(vis1));
//				memset(vis2,-1,sizeof(vis2));
				Sum=0;
				
				DFS1(i,j);
				min_len=vis1[i];
				
				DFS2(i,j,0);
				ans+=(Sum==2);
			}
		}
		
		std::cout<<ans<<'\n';
	}

    return 0;
}
