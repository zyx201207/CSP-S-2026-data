#include <bits/stdc++.h> 
using namespace std;
const int N = 3e5 + 10;
const int M = 3e5 + 10;
int n,m,a[N],b[M];
bool f[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	deque <int> q(m * n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",a + i);	
	}for(int i = 1;i <= n;i ++){
		memset(f,false,sizeof(f));
		for(int j = i;j <= n;j ++){
			if(f[a[j]]){
				while(1){
					f[q.back()] = false;
					q.pop_back();
					if(q.back() == a[j]){
						q.pop_back();
						break;
					}
				}
			}q.push_back(a[j]);
			f[a[j]] = true;
		}while(!q.empty()){
			b[q.front()] ++;
			q.pop_front();
		}
	}for(int i = 1;i <= m;i ++){
		printf("%d ",b[i]);
	}return 0;
}
/*
12

10 3
3 1 2 1 3 2 3 1 2 1
*/
