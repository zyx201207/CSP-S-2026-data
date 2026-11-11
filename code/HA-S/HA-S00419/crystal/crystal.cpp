#include<bits/stdc++.h>
using namespace std;
const long long N=1e6+10;
long long a[N]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+1);
	for(int i=0;i<m;i++){
		int s=i;
		for(int j=1;j<=m;j++){
			if(a[j]+s==a[j+1]){
				num++;
				m-=s;
				break;
			}
		}
	}
	if(num!=0){
		cout<<num+1;
		return 0;
	}else{
		cout<<num;
	}
	return 0;
} 



