//GZ-S00144 贵阳市南明区李端棻中学 周熙沅
#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n-1,cmp);
	for(int i=0;i<m;i++){
		if(a[0]==a[1])a[0]++;
		else{
			int b=0;
			for(int j=0;j<n-1;j++){
				if(a[j]-1==a[j+1]){
					b=j+1;
					break;
				}else if(a[j]+1==a[j+1]){
					b=j;
					break;
				}
			}
			a[b]++;
		}
	}
	int cnt=0;
	for(int i=0;i<n-1;i++){
		if(a[i]==a[i+1]){
			cnt++;
		}else if(a[i-1]==a[i]&&i!=0){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}
