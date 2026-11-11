#include<iostream>
using namespace std;
struct S{
	int num;
	int pos;
}l[33333];
int a[55555],ans[33333];
int main(){
	freopen("card.in",'r',stdin);
	freopen("card.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;++i){
		cin>>a[i];
		l[i].num=0;
	}
	for(int i=0;i<n;++i){
		int len=0;
		for(int j=i;j<n;++j){
			if(l[a[j]].num==1){
				for(int k=l[a[j]].pos;k<len;++k){
					l[a[k+i]].num=0;
				}
				l[a[j]].num=1;
				len=l[a[j]].pos;
			}
			else{
				len++;
				l[a[j]].num++;
				l[a[j]].pos=len-1;
			}
		}
		for(int j=1;j<=m;++j){
			ans[j]+=l[j].num;
			l[j].num=0;
		}
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
} 
