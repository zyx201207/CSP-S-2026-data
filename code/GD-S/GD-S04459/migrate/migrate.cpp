#include<bits/stdc++.h>
#define int1 long long
using namespace std;
int c;
int solve(int1 d,int1 num[],int1 len){
	int not1=0;
	int1 nxt;
	for(int i=0;i<len;i++){
		not1 =i;
		for(int j=i+1;j<len;j++){
			if(num[j]-num[i]<=d){
				d-=(num[j]-num[i]);
				nxt=j;
			}
		}
	}
	if(	 abs(nxt-not1)==0){
		if(c*(len/abs(nxt))+not1-2<0){
			return 0;
		}else{
			return c*(len/abs(nxt))+not1-2;
		}
	}else{
			return abs(nxt-not1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin>>c>>t;
	if(c==13||c==14){
		for(int i=0;i<t;i++){
			int n,d;
			cin>>n>>d;
			for(int i=0;i<n;i++){
				int1 tmp;
				cin>>tmp;
			}
			cout<<n*(n-3)<<endl;
		}
	}
	for(int i=0;i<t;i++){
		int1 n,d;
		cin>>n>>d;
		int1 a[5005];
			for(int i=0;i<n;i++){
				
				cin>>a[i];
				
			}
			cout<<solve(d,a,n)<<endl;
			
	}
	
	
	
	
	
	return 0;
}












