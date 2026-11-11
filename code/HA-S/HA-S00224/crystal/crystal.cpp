#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
const int MAXN=50005;
int a[MAXN];
int n;
long long m;
bool px(int a,int b){
	return a<b;
}
bool check(int x,int y){
	int mid=(x+y)/2;
	for(int i=1;i<=n;i++){
		int sum=0;
		int js=2;
		for(int j=i;j<n;j++){
				sum+=(a[j+1]-a[j])*(js-1);
				if(js>=mid){
					break;
				}
				else{
					js++;
				}
		}
		if(sum<m){
			return 1;
		}		
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdout);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	sort(a+1,a+n+1,px);
	for(int i=1;i<n;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]){
			flag=0;		
		}
	}
	long long ans=0;
	if(flag==1){
		ans=m/(a[1]-a[0])+1;
		cout<<ans;
	}
	if(flag==0){
		int l=1;
		int r=n;	
		while(l<r){
			if(check(l,r)==1){
				l=1+(l+r)/2;
			}
			else{
				r=(l+r)/2-1;
			}
		}	
		cout<<l-1;
	}
	return 0;
}
