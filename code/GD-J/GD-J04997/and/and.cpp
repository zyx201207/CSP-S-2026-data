#include <bits/stdc++.h>
using namespace std;
long long m,n,maxx;
long long cnt;
long long ans=0,p;
long long arr[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >>n >>m;
	for(int i=1;i<=n;i++){
		cin >>arr[i];
		maxx=max(maxx,arr[i]);
	}
	
	while(maxx>0){
		maxx=maxx>>1;
		cnt++;//weishu
	}
	//cout <<cnt;
	
	while(cnt--){
		p=0;
		for(int i=1;i<=n;i++){
			if((arr[i]>>cnt)>=0 && (arr[i]>>cnt)%2==1){
				//这一位是1
				p++; 
			}
		}
		if(p>=m){
			ans+=1<<cnt;
			//cout <<"yes-" <<p <<'\n'; 
			for(int i=1;i<=n;i++){
			if(!((arr[i]>>cnt)>=0 && (arr[i]>>cnt)%2==1)){
				arr[i]=0;
			}
		}
		}
	}
	cout <<ans;
}
