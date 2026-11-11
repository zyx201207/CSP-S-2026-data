#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	int maxn=0,cnt=0;
		if(m==1){
		
		
			int sum=a[i],num=a[i+1];
			max(sum,num);
			if(max(sum,num)==sum){
				cnt=sum;
			}else{
				cnt=num;
			}
			sum=cnt;
		
		cout<<cnt;
		}
	}
	
}
