#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int n,m,a[200010],ans=-1,tt=-1,ff,dd=-1;                                                                                                                                                                           
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		tt=max(tt,a[i]);
	}
	if(m==1){
		cout<<tt;
		return 0;
	}
	if(m==n){
		ff=a[1]&a[2];
		for(int i=3;i<=n;i++){
			ff&=a[i];
		}
		cout<<ff;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dd=max(dd,a[i]&a[j]);
			}
		}
		cout<<dd;
		return 0;
	}
	int xxx=a[1];
	if(m<=20&&n<=20){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				xxx&=a[j];
				for(int k=j+1;k<=n;k++){
					xxx&=a[k];
					for(int c=k+1;c<=n;c++){
						xxx&=a[c];
						for(int d=c+1;d<=n;d++){
							xxx&=a[d];
							for(int e=d+1;e<=n;e++){
								xxx=max(xxx,xxx&=a[e]);
							}
						}
					}
				}
			}
		}
		cout<<xxx;
		return 0;
	}
	sort(a+1,a+1+n,cmp);
	int xx=a[1]&a[2];
	for(int i=3;i<=m;i++){
		xx&=a[i];
	}
	cout<<xx;
	return 0;
} 
/*
in:5 2
31 3 1 15 7

4 2
3 15 12 12
out:
*/
