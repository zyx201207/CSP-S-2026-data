#include <bits/stdc++.h>
using namespace std;
struct duan{
	long long m;
	char zi;
};
duan du[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	long long n,cnt=0;
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>du[i].m>>du[i].zi;
	}
	long long l=1,r=n;
	while(l<r){
		if(du[l].zi != du[r].zi){
			cnt+=min(du[l].m,du[r].m);
			if(du[l].m>=du[r].m){
				du[l].m-=du[r].m;
				du[r].m=0;
			}
			else{
				du[l].m-=du[r].m;
				du[r].m=0;
			}
			
		}
		if(du[r].m==0){
			r--;
		}
		if(du[l].m==0){
			l++;
		}
		
	}
	cout<<cnt;



	return 0;
} 
