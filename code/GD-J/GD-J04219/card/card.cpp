#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
bool cnt[300005];
stack<int> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int x=1;x<=n;x++){
		for(int i=1;i<=m;i++){
			cnt[i]=0;
		}
		for(int i=x;i<=n;i++){
			while(cnt[a[i]]&&(!s.empty())){
				cnt[s.top()]=0;
				s.pop();
			}
			s.push(a[i]);
			cnt[a[i]]=1;
		}
		while(!s.empty()){
			s.pop();
		}
		for(int i=1;i<=m;i++){
			if(cnt[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
	return 0;
}
