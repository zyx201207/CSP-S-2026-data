#include<bits/stdc++.h>
using namespace std;
vector<char> q;
long long n,ans=0,cnt=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long k=0;
	char zm;
	for(int i=1;i<=n;i++){
		cin>>k>>zm;
		ans=ans+k;
		for(int j=1;j<=k;j++){
			q.push_back(zm);
		}
	}
	char x,y;
	if(ans%2==0){
		for(int i=0;i<ans/2;i++){
			x=q[i];
			y=q[ans-1-i];
			if(x!=y){
				cnt++;
			}
		}
	}else{
		for(int i=0;i<ans/2;i++){
			x=q[i];
			y=q[ans-i-1];
			if(x!=y){
				cnt++;
			}
		}
	}	
	cout<<cnt;
	return 0;
}
