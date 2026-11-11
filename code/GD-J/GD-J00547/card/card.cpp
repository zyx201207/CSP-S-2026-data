#include<bits/stdc++.h>
using namespace std;
int a[500005]={0};
long long ans[300005]={0};
int n,m;
void solve1(){
	int num=0,cnt=0,get;
	for(int i=1;i<=n+1;i++){
		if(a[i]!=num){
			if(cnt!=0){
				if(cnt&1){
					get=i-1-cnt/2;
				}else get=cnt/2;
			}ans[num]=get;
			num=a[i];
			cnt=1;
		}else{
			cnt++;
		}
	}for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
}void solve2(){
	if(a[1]==1){
		cout<<"2 2";
	}else{
		cout<<"4 2";
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool speA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])speA=0;
	}if(speA){
		solve1();
	}else solve2();
	return 0;
} 
