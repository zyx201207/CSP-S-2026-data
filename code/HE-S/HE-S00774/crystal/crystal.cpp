#include<iostream>
const int N = 10005;
long long n,m,ans,num,as;
int a[N];
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i = 0;i<=m;i++){
		as = a[i]+=1; 
		for(int j = 0;j>=m;j++){
			if(as==a[i]){
				num++;
				if(num>=ans){
					break;
				}
				else{
					ans=num;
				}
			}
		}
	}
	cout<<ans;
	return 0;
	
} 
