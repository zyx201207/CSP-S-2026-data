#include<bits/stdc++.h>
using namespace std;
long long a[1000500];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int x,y;
	while(m--){
		int sum=0;
		int cnt=0;
		cin>>x>>y;
		for(int i=1;i<=x;i++){
			cin>>a[i];
		}
		for(int i=1;i<=x;i++){
			if(a[i]<0){
				cnt++;
			}
		}
		sort(a+1,a+n+1);
		if(x==4&&a[1]>=0){
			sum+=1;
		}else if(a[1]>=0&&x>4){
			sum+=x/4+1;
		}else if(x>=4&&a[4]<0){
			sum+=1;
		}else if(a[cnt]<0&&cnt>4){
			sum+=x/4+1;
		}
		cout<<sum;
	}
	return 0;
} 
