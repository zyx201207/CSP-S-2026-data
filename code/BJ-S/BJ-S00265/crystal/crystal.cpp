# include <bits/stdc++.h>
using namespace std;
long long n,m,a[10000000],cnt,ant,bnt;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int dnt=-1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(dnt<ant){
			dnt=ant;
		}
		ant=1;
		cnt=0;
		bnt=m;
		if(i==1){
			continue;
		}
		for(int j=1;j<=n;j++){
			cnt=a[j]-a[i];
			if(cnt<0){
				continue;
			}else if(cnt==0){
				ant++;
			}else{
				if(cnt<=bnt){
					bnt-=cnt;
					ant++;
				}else{
					continue;
				}
			}
		}
	}
	cout<<dnt;
return 0;
}
