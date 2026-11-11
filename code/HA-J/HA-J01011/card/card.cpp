#include<bits/stdc++.h>
using namespace std;
int a[500005],s[300005],ta[300005],n,m;
void play_(int num){
	int all_=0;
	for(int i=num;i<=n;i++){
		int have_=0,plac=0;
		for(int j=1;j<=all_;j++){
			if(ta[j]==a[i]){
				have_=1;
				plac=j;
			}
		}
		if(!have_) ta[++all_]=a[i];
		else{
			for(int j=plac+1;j<=all_;j++) ta[j]=0;
			all_-=all_-plac;
		}
	}
	for(int i=1;i<=all_;i++) s[ta[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) play_(i);
	for(int i=1;i<=m;i++) cout<<s[i]<<' ';
	return 0;
}
