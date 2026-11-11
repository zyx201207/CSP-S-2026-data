#include<iostream>
#include<cstdio>
using namespace std;
long long n,m,a[1000005],b[1000005]={};
struct queue{
	int x;
	bool y;
}q[1000005];
void bfs(long long ii){
	struct queue t[1000005]={};
	long long head=0,j=ii;
	while(j<=n){
		if(!t[a[j]].y){
			head++;
			t[a[j]].x=head;
			t[a[j]].y=1;
			q[head].x=a[j];
		}else{
			for(int i=t[a[j]].x+1;i<=head;i++){
				t[q[i].x].x=0;
				t[q[i].x].y=0;
			}head=t[a[j]].x;
		}
		j++;
	}
	for(long long i=1;i<=m;i++){
		if(t[i].y){
			b[i]++;
		}
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}for(long long i=1;i<=n;i++){
		bfs(i);
	}for(long long i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
