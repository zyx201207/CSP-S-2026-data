#include<bits/stdc++.h>
#define MAXN 500010 
using namespace std;
int n,m,a[MAXN],ans[MAXN];
namespace Subtask1{
	int last[MAXN];
	inline void play(int start){
		deque<int> q;
		fill(last+1,last+1+m,0);
		for(int i=start;i<=n;++i){
			if(!last[a[i]]){
				q.push_back(a[i]);
				last[a[i]]=true;
			}else{
				while(!q.empty()&&q.back()!=a[i]){
					last[q.back()]=false;
					q.pop_back();
				}
			}
		}
		for(deque<int>::iterator i=q.begin();i!=q.end();++i){
			++ans[*i];
		}
	}
	int Main(){
		for(int i=1;i<=n;++i){
			play(i);
		}
		for(int i=1;i<=m;++i){
			printf("%d ",ans[i]);
		}
		return 0;
	}
}
namespace Subtask2{
	int Main(){
		if(m==1){
			printf("%d",n);
			return 0;
		}
		int cnt[2]={0};
		for(int i=1;i<=n;++i){
			++cnt[a[i]-1];
		} 
		cnt[a[n]-1]=n;
		printf("%d %d",cnt[0],cnt[1]);
		return 0;
	}
}
namespace Subtask3{
	int Main(){
		a[0]=a[1];
		for(int i=1;i<=n;++i){
			if(a[i]!=a[i+1]){
				printf("%d ",i);
			}
		}
		return 0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	bool F=true;
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i-1]>a[i]){
			F=false;
		}
	}
	if(F){
		return Subtask3::Main();
	}else if(m<=2){
		return Subtask2::Main();
	}
	return Subtask1::Main();
}

