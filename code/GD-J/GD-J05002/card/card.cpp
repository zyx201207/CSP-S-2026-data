#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		int maxn=0,cnt=0;
		for(int i=1;i<=n;i++){
			int sum=a[i],num=a[i+1];
			max(sum,num);
			if(max(sum,num)==sum){
				cnt=sum;
			}else{
				cnt=num;
			}
			sum=cnt;
		}
		cout<<cnt;
	}
}
